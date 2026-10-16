% Masse des Quadcopters 0.5 bis 2kg
m = 0.965;

% Trägheitsmomente des Quadcopters
I_xx = 0.01;
I_yy = 0.01;
I_zz = 0.02;

% Erdbeschleunigung
g = 9.81;

% Abstand zwischen Motor und Schwerpunkt
L = 0.225;

% Trägheitsmoment der Propeller Blades
J_r = 5.33 * 10^-5;

% Winkelgeschwindigkeit des Motors
Omega_d = 995;

% Gesamtschubkraft
U_1 = 25.72;

% Drehmomente
U_2 = 0.2;
U_3 = 0.5;
U_4 = 0.25;