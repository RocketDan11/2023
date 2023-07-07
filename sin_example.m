clc;
clear all;
close all;

t = 0 : 0.1 : 2*pi % start at 0/ increment by 0.1 / until 2pi
t1 = 0 : 0.1 : 2*pi
g = cos(t);
f = sin(t);
plot(t,f)
hold on
plot(t1,g);
xlabel('t'); ylabel('f(t)');
grid on
x = diff(g);
