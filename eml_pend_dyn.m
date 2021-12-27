function y = pend_dyn(u)
m = 1;
M = 1;
l = 1;
J = 1;
g = 9.8;
c = 1;
lam=1;
F           = u(1);
theta       = u(2);
% theta_dot   = u(3)
% x           = u(4)
% x_dot       = u(5)
% MM = (m+M)
% jml= (J+m*l^2)
% mlc = m*l*cos(theta)
% mls = m*l*sin(theta)
% MMatrix = [MM -mlc;-mlc jml]
% MMatrix_inv = inv(MMatrix)
% Fmat = [F;0]
% dyn = [c*x_dot+mls*theta_dot^2;lam*theta_dot-g*mls]
% y = MMatrix_inv*(Fmat-dyn)
y = F+theta;
end

