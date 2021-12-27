% -------------------------------------------------------------------
%  Pendulum init file. Sam Nazari, Ph.D.
% -------------------------------------------------------------------
saveVarsMat = load('pend_init.mat');

A = mpt.Parameter;
A.Value = [0 1];
A.CoderInfo.StorageClass = 'Custom';
A.CoderInfo.Alias = '';
A.CoderInfo.Alignment = -1;
A.CoderInfo.CustomStorageClass = 'Global';
A.CoderInfo.CustomAttributes.MemorySection = 'Default';
A.CoderInfo.CustomAttributes.HeaderFile = '';
A.CoderInfo.CustomAttributes.DefinitionFile = '';
A.CoderInfo.CustomAttributes.Owner = '';
A.CoderInfo.CustomAttributes.PersistenceLevel = 1;
A.Description = '';
A.DataType = 'auto';
A.Min = [];
A.Max = [];
A.DocUnits = '';

B = mpt.Parameter;
B.Value = [0; 1];
B.CoderInfo.StorageClass = 'ExportedGlobal';
B.CoderInfo.Alias = '';
B.CoderInfo.Alignment = -1;
B.Description = '';
B.DataType = 'auto';
B.Min = [];
B.Max = [];
B.DocUnits = '';

Ts = mpt.Parameter;
Ts.Value = 0.005;
Ts.CoderInfo.StorageClass = 'ExportedGlobal';
Ts.CoderInfo.Alias = '';
Ts.CoderInfo.Alignment = -1;
Ts.Description = '';
Ts.DataType = 'auto';
Ts.Min = [];
Ts.Max = [];
Ts.DocUnits = '';

X0 = Simulink.Parameter;
X0.Value = 0;
X0.CoderInfo.StorageClass = 'ExportedGlobal';
X0.CoderInfo.Alias = '';
X0.CoderInfo.Alignment = -1;
X0.Description = '';
X0.DataType = 'auto';
X0.Min = [];
X0.Max = [];
X0.DocUnits = '';

ans = 'Variable ''Ts'' has been created.';

g = mpt.Parameter;
g.Value = 9.8;
g.CoderInfo.StorageClass = 'ExportedGlobal';
g.CoderInfo.Alias = '';
g.CoderInfo.Alignment = -1;
g.Description = '';
g.DataType = 'auto';
g.Min = [];
g.Max = [];
g.DocUnits = '';

k = mpt.Parameter;
k.Value = 100;
k.CoderInfo.StorageClass = 'ExportedGlobal';
k.CoderInfo.Alias = '';
k.CoderInfo.Alignment = -1;
k.Description = '';
k.DataType = 'auto';
k.Min = [];
k.Max = [];
k.DocUnits = '';

l = mpt.Parameter;
l.Value = 2;
l.CoderInfo.StorageClass = 'ExportedGlobal';
l.CoderInfo.Alias = '';
l.CoderInfo.Alignment = -1;
l.Description = '';
l.DataType = 'auto';
l.Min = [];
l.Max = [];
l.DocUnits = '';

m = mpt.Parameter;
m.Value = 50;
m.CoderInfo.StorageClass = 'ExportedGlobal';
m.CoderInfo.Alias = '';
m.CoderInfo.Alignment = -1;
m.Description = '';
m.DataType = 'auto';
m.Min = [];
m.Max = [];
m.DocUnits = '';

t_out = Simulink.Signal;
t_out.CoderInfo.StorageClass = 'ExportedGlobal';
t_out.CoderInfo.Alias = '';
t_out.CoderInfo.Alignment = -1;
t_out.Description = '';
t_out.DataType = 'auto';
t_out.Min = [];
t_out.Max = [];
t_out.DocUnits = '';
t_out.Dimensions = -1;
t_out.DimensionsMode = 'auto';
t_out.Complexity = 'auto';
t_out.SampleTime = -1;
t_out.InitialValue = '';

tf = 20;

theta = mpt.Signal;
theta.CoderInfo.StorageClass = 'ExportedGlobal';
theta.CoderInfo.Alias = '';
theta.CoderInfo.Alignment = -1;
theta.Description = '';
theta.DataType = 'auto';
theta.Min = [];
theta.Max = [];
theta.DocUnits = '';
theta.Dimensions = -1;
theta.DimensionsMode = 'auto';
theta.Complexity = 'auto';
theta.SampleTime = -1;
theta.InitialValue = '';

theta_dot = mpt.Signal;
theta_dot.CoderInfo.StorageClass = 'ExportedGlobal';
theta_dot.CoderInfo.Alias = '';
theta_dot.CoderInfo.Alignment = -1;
theta_dot.Description = '';
theta_dot.DataType = 'auto';
theta_dot.Min = [];
theta_dot.Max = [];
theta_dot.DocUnits = '';
theta_dot.Dimensions = -1;
theta_dot.DimensionsMode = 'auto';
theta_dot.Complexity = 'auto';
theta_dot.SampleTime = -1;
theta_dot.InitialValue = '';

tout = saveVarsMat.tout; % <4001x1 double> too many elements

u = Simulink.Parameter;
u.Value = 0;
u.CoderInfo.StorageClass = 'ExportedGlobal';
u.CoderInfo.Alias = '';
u.CoderInfo.Alignment = -1;
u.Description = '';
u.DataType = 'auto';
u.Min = [];
u.Max = [];
u.DocUnits = '';

x_ddot_0 = Simulink.Parameter;
x_ddot_0.Value = 0.1;
x_ddot_0.CoderInfo.StorageClass = 'ExportedGlobal';
x_ddot_0.CoderInfo.Alias = '';
x_ddot_0.CoderInfo.Alignment = -1;
x_ddot_0.Description = '';
x_ddot_0.DataType = 'auto';
x_ddot_0.Min = [];
x_ddot_0.Max = [];
x_ddot_0.DocUnits = '';

x_dot_0 = Simulink.Parameter;
x_dot_0.Value = 0;
x_dot_0.CoderInfo.StorageClass = 'ExportedGlobal';
x_dot_0.CoderInfo.Alias = '';
x_dot_0.CoderInfo.Alignment = -1;
x_dot_0.Description = '';
x_dot_0.DataType = 'auto';
x_dot_0.Min = [];
x_dot_0.Max = [];
x_dot_0.DocUnits = '';

yout = saveVarsMat.yout; % <1x1 Simulink.SimulationData.Dataset> unsupported class

clear saveVarsMat;
