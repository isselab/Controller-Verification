clear

%% Initialize variables
angle_change_start_time = 1;
initial_angle = 0;
final_angle = 1;
epsilon = 0.01;


%% Simulate
simOut = sim('satellite_attitude', 'ReturnWorkspaceOutputs', 'on');
disp(class(simOut))
% Determine control system performance
ds = simOut.logsout;
disp(class(ds))
signal = ds.getElement(1);
disp(class(signal))
zeit = signal.Values.Time;
disp(class(zeit))
werte = signal.Values.Data;
disp(class(werte))
% Rise time
idx = find(werte > final_angle*0.9, 1, 'first');
riseTime = zeit(idx) - angle_change_start_time;

% Settling time
settlingTime = NaN;
for i = 1:length(werte)
    if abs(werte(i) - final_angle) < (epsilon * final_angle)
        if isnan(settlingTime)
            settlingTime = zeit(i);
        end
    else
        settlingTime = NaN;
    end
end

% Overshoot
overshoot = (max(werte) - final_angle) / final_angle;

% Steady state error
steadyStateError = abs(werte(end) - final_angle) / final_angle;

%% Show results

signal2 = ds.getElement(2);
setpoints = signal2.Values.Data;

h1 = plot(zeit, setpoints, 'r-', 'LineWidth', 2);
hold on
h2 = plot(zeit, werte, 'b-','LineWidth', 2);
hold off

xlabel('Time [s]', 'FontSize', 14)
ylabel('Yaw Orientation', 'FontSize', 14)
legend([h2 h1],'controlled value', 'set-point value')
grid on

xlim([0 4])
ax = gca;               % aktuelles Achsenobjekt
ax.FontSize = 14; 
annotation('textbox', [0.36, 0.3, 0.4, 0.2], 'String', ...
    { ...
        ['Rise Time: ' num2str(riseTime) 's'], ...
        ['Settling Time: ' num2str(settlingTime) 's'], ...
        ['Maximum Overshoot: ' num2str(overshoot*100) '%'], ...
        ['Steady State Error: ' num2str(steadyStateError*100) '%']
    }, 'FontSize', 14, 'FitBoxToText', 'on');
