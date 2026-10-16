%% Speed Controller

clear; clc;

%% Model and Parameter

Ts = 0.1;   % sample time
T = 30;     % simulation time

%% launch simulation

out = sim("Velocity_Controlled_Vehicle.slx",T);

%% Properties

ST = 0.05; % settling time threshold
RT = [0.0 0.9]; % rise time threshold

S = stepinfo(out.resp_v_c.signals.values, out.tout, 'SettlingTimeThreshold', ST, 'RiseTimeLimits', RT)
