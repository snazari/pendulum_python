import ctypes
import os
import platform
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from rtwtypes import *

def get_vars():
    # Load Shared Object
    dll_path = os.path.abspath("pend.so")
    dll = ctypes.cdll.LoadLibrary(dll_path)

    # Connect shared variables
    theta = real_T.in_dll(dll, "theta")
    theta_dot = real_T.in_dll(dll, "theta_dot")
    t = real_T.in_dll(dll, "t_out")
    u = real_T.in_dll(dll, "u")
    k = real_T.in_dll(dll,"k")
    l = real_T.in_dll(dll,"l")
    m = real_T.in_dll(dll,"m")
    g = real_T.in_dll(dll,"g")
    B = real_T.in_dll(dll,"B")
    return u, t, l, m, k, g, B, theta, theta_dot, dll

def pi_control(row, r):
    Ki = 1
    Kp = 0
    theta_t = row[-1]['theta']
    theta_tm1=[row[i]['theta'] for i in range(len(row))]
    e = r - theta_t
    integral_action=np.trapz(theta_tm1)
    print(integral_action)
    u = Kp*e + Ki*integral_action
    #print(e*57.3)
    return u, e

if __name__ == "__main__":
    # Get main vars
    u, t, l, m, k, g, B, theta, theta_dot, dll = get_vars()
    # Set model init(), step() and term() functions.
    model_initialize = dll.pend_initialize
    model_step = dll.pend_step
    model_terminate = dll.pend_terminate

    # Init()
    model_initialize()

    # Run a test
    Fs = 200
    Ts = 1 / Fs
    row = list()
    k.value = 1
    m.value = 1.0
    l.value = 1
    B.value = 1/(m.value*l.value**2)
    e = 0
    u.value = 0.0
    for step in range(25 * Fs):
        model_step()
        row.append(
            {
                "time": float(t.value),
                "u": float(u.value),
                "theta": float(theta.value),
                "theta_dot": float(theta_dot.value),
                "error":float(e)
            }
        )
        u.value,e = pi_control(row,np.pi/2)
    df = pd.DataFrame(row)
    plt.figure(figsize=(20, 8))
    plt.title("Output of System", size=35)
    plt.plot(df.time, df.theta, 'b-')
    plt.plot(df.time, df.theta_dot, 'r-')
    plt.plot(df.time, df.u, 'k--')
    plt.plot(df.time, df.error, 'g-.')
    plt.xlabel('Time (sec)', size=20)
    plt.ylabel('Amplitude', size=20)
    plt.ylim([-np.pi,np.pi])
    plt.grid()
    plt.legend(['theta', 'theta_dot', 'control', 'error'])
    plt.show()