%% Initialize variables
angle_change_start_time = 1;
initial_angle = 0;
final_angle = 1;
epsilon = 0.01;
Kp = 30.7142;
Ki = 2.480;
Kd = 1.10844;

%% Simulate
simOut = sim('UAV');

% Determine control system performance
%%
time = simOut.yout.getElement('Reference').Values.Time;
reference = simOut.yout.getElement('Reference').Values.Data;
output = simOut.yout.getElement('Output').Values.Data;

% Rise time
riseTime = time(find(output >= final_angle, 1)) - angle_change_start_time;

% Settling time
settlingTime = NaN;
for i = 1:length(time)
    if abs(output(i) - final_angle) < (epsilon * final_angle)
        if isnan(settlingTime)
            settlingTime = time(i);
        end
    else
        settlingTime = NaN;
    end
end

% Overshoot
overshoot = (max(output) - final_angle) / final_angle;

% Steady state error
steadyStateError = abs(output(end) - final_angle) / final_angle;

%% Show results
xLimits = xlim;
yLimits = ylim;

xRange = xLimits(2)-xLimits(1);
yPatch = [yLimits(1) yLimits(2) yLimits(2) yLimits(1)];

% Divide x-axis into stripes
xLines = [0.5 0.03 0.02 0.04 0.025 0.02 0.06 0.15];
xPoints = zeros(1, length(xLines) + 2);
xPoints(1) = xLimits(1);
for i = 2:length(xLines)+1
    xPoints(i) = xPoints(i-1) + xRange * xLines(i-1);
end
xPoints(end) = xLimits(2);

colors = [
    [0.8 1 0.8];  % light green (rest)
    [1 0.9 0.7];  % light orange (transient)
    [0.8 0.9 1];    % light blue (rise)
    [1, 0.8, 0.8]  % light red (overshoot)
    [1 0.9 0.7];  % light orange (transient)
    [0.85 0.8 1];  % light purple (bounded)
    [1 0.9 0.7];  % light orange (transient)
    [0.85 0.8 1];  % light purple (bounded)
    [0.8 1 0.8];  % light green (rest)
];

patches = zeros(1, length(xPoints)-1);

hold on
for i = 1:length(xPoints)-1
    patches(i) = patch([xPoints(i) xPoints(i) xPoints(i+1) xPoints(i+1)], ...
          yPatch, colors(i,:), 'EdgeColor', 'none');
end

reference_plot = plot(time, reference, 'r-', 'LineWidth', 2);
output_plot = plot(time, output, 'b-','LineWidth', 2);

legend([patches(1) patches(2) patches(3) patches(4) patches(6) reference_plot output_plot], ...
        {'Rest', 'Transient', 'Rise', 'Overshoot', 'Bounded', 'Set-point value', 'Controlled value'}, ...
        'Location', 'northwest');
xlabel('Time [s]', 'FontSize', 14)
ylabel('Pitch Orientation', 'FontSize', 14)
hold off

annotation('textbox', [0.14, 0.4, 0.4, 0.2], 'String', ...
    { ...
        ['Rise Time: ' num2str(riseTime) 's'], ...
        ['Settling Time: ' num2str(settlingTime) 's'], ...
        ['Maximum Overshoot: ' num2str(overshoot*100) '%'], ...
        ['Steady State Error: ' num2str(steadyStateError*100) '%']
    }, 'FontSize', 8, 'FitBoxToText', 'on', 'BackgroundColor', 'white');

