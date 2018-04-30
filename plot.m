close all; clear all; clc;
A=load('KFTrajectory_5.txt');
x_Camera=A(:,2);
y_Camera=A(:,4);
z_Camera=A(:,3);
plot3(x_Camera,y_Camera,z_Camera,'.')
title('Camera Trajectory(VO Estimated)')
xlabel('x');ylabel('y');zlabel('z');
grid on;