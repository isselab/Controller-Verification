clear; clc;

%% Model
mdl = 'my_mpcACCsystem';
open_system(mdl)

Ts = 0.1;
T = 80;

G_ego = tf(1,[0.5,1,0]);

x0_lead = 50;   % initial position for lead car (m)
v0_lead = 25;   % initial velocity for lead car (m/s)
A_acc_lead = 0.6; % Amplitude of sinusoidal acceleration (m/s^2)

x0_ego = 10;   % initial position for ego car (m)
v0_ego = 20;   % initial velocity for ego car (m/s)

t_gap = 1.4;
D_default = 10;

v_set = 30;

amin_ego = -1;
amax_ego = 1;

%% Launch sim
out=sim(mdl);

%% Plotting results
time = out.tout;
data = out.logsout;

mode = data{1}.Values.Data;

safe_distance = data{3}.Values.Data;

p_lead = data{9}.Values.Data;
v_lead = data{10}.Values.Data;
a_lead = data{12}.Values.Data;

p_ego = data{7}.Values.Data;
v_ego = data{8}.Values.Data;
a_ego = data{6}.Values.Data;


figure(1); clf;
subplot(411); hold on;
grid on;
plot(time,p_lead - p_ego);
plot(time,safe_distance);
plot(time,D_default*ones(size(time)));
xlabel('time');
ylabel('Distance (m)');
legend('Relative distance', 'Safe distance','Minimum distance');

subplot(412); hold on;
grid on;
plot(time,v_lead);
plot(time,v_ego);
plot(time,v_set*ones(size(time)));

xlabel('time');
ylabel('Velocity (m/s)');
legend('v lead', 'v ego');

subplot(413); hold on;
grid on;
plot(data{11}.Values.Time,a_lead);
plot(time,a_ego);

% plot saturations
plot(time,amin_ego*ones(size(time)),'k:');
plot(time,amax_ego*ones(size(time)),'k:');

xlabel('time');
ylabel('Acceleration (m/s^2)');
legend('a lead', 'a ego','a min', 'a max');


subplot(414); hold on;
grid on;
stairs(time,mode);

xlabel('time');
ylabel('Mode');

figure(2); clf;
hold on;
grid on;
plot(time,p_lead);
plot(time,p_ego);
xlabel('Time');
ylabel('Position');
legend('Lead','Ego');

% rmpath(fullfile(matlabroot,'examples','mpc','main'));
% bdclose(mdl)

