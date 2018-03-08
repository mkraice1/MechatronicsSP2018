%% 530.421 Mechatronics: Mouse & Cat simulation
%% Simulation setup
% testing field size
fsize = 100; % every grid element in field is 0.1m by 0.1m
% time interval
time_step = 1; % 1 second is time step
% mouse's center of motion
Row_Cmouse = 30;
Col_Cmouse = 50;
% mouse's initial position
Row_mouse_init = 30;
Col_mouse_init = 64;
% cat's initial position
Row_cat_init = 100;
Col_cat_init = 100;
% cat's speed constraint
Vel_cat_min = 0.1; % minimum speed in m/s
Vel_cat_max = 0.3; % maximum speed in m/s
%% Field of simulation
Field = zeros(fsize, fsize, 3); %make a square grid
%% Mouse's motion
% mouse's center of motion
Cmouse = [Row_Cmouse, Col_Cmouse]; %center of mouse's motion (50, 70) on grid
Cmouse_xy = [Col_Cmouse, 100-Row_Cmouse]; %convert to xy coordinates
% mouses's motion can be described by state vector [x, y]
% which are coordinates on grid
Pmouse  = [Row_mouse_init, Col_mouse_init]; % original mouse's position in grid
% parameters
Rmouse = 15; % radius of mouse's motion
ang_val = 0.2; % rads/second
theta_step = ang_val * time_step; % angle covered in each time step, radians
%% Cat's motion
% cat's motion can be described by state vector [x, y]
% which are coordinates on grid
Pcat = [Row_cat_init, Col_cat_init]; % original position of cat
%% PID control (Cat's motion) parameters you can play with
Kp = 0.3; % propotional factor used to adjust cat's speed
Ki = 0.008; % integral factor
Kd = 0.6; % differential factor
%% Simulate Mouse's motion & Cat's motion
theta = 0;
diff_vector_prev = [0, 0];
sum_diff = 0;
for i = 1:100
    % display iteration message in command window
    message0 = sprintf('iteration: %d', i);
    disp(message0);
    
    % update cat's motion
    Pcat_xy = [Pcat(2), fsize-Pcat(1)];
    Pmouse_xy = [Pmouse(2), fsize - Pmouse(1)];
    % PI control law
    diff_vector = Pmouse_xy - Pcat_xy;
    add_vector = round(Kp*diff_vector + Ki*sum_diff*diff_vector + Kd*(diff_vector - diff_vector_prev)/time_step);
    % consider speed constraint, limit magnitude of add_vector
    if norm(add_vector)/time_step < Vel_cat_min*10
        add_vector = add_vector + [0.01, 0.01]; % regularization term, in case add_vector = [0, 0]
        add_vector = round(add_vector/norm(add_vector)*(Vel_cat_min*10));
    elseif norm(add_vector)/time_step > Vel_cat_max*10
        add_vector = round(add_vector/norm(add_vector)*(Vel_cat_max*10));
    end
    % Assume perfect cat robot control, its new position is just as desired
    Pcat_xy = Pcat_xy + add_vector;
    Pcat = [100-Pcat_xy(2), Pcat_xy(1)];
    diff_vector_prev = diff_vector;
    sum_diff = sum_diff + norm(diff_vector_prev);
    
    % display cat's updates state
    message1 = sprintf("Cat's state: [%d, %d]", Pcat_xy(1), Pcat_xy(2));
    disp(message1);
    
    % update mouses's motion
    theta = theta + theta_step;
    Pmouse_xy = Cmouse_xy + [round(Rmouse*cos(theta)), round(Rmouse*sin(theta))];
    Pmouse = [fsize-Pmouse_xy(2), Pmouse_xy(1)];
    
    % display mouse's update state
    message2 = sprintf('Mouse state: [%d, %d]\n', Pmouse_xy(1), Pmouse_xy(2));
    disp(message2);
    
    % visualize mouse's and cat's motion
    Field(Pmouse(1), Pmouse(2), :) = [255, 0, 0];
    Field(Pcat(1), Pcat(2), :) = [0, 255, 0];
    imshow(Field, 'InitialMagnification', 800);
    Field(Pmouse(1), Pmouse(2), :) = [0, 0, 0];
    Field(Pcat(1), Pcat(2), :) = [0, 0, 0];
end
%% Note:
% if simulation is good, your Cat's state in 100th iteration will be very
% close to Mouse's state in 99th iteration, even the same !

