function busdef()


%% double data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'time_frame';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'double';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'Lat_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'double';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'Long_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'double';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'Lat';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'double';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'Long';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'double';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');


BUS_double_log_t = Simulink.Bus;
BUS_double_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_double_log_t.DataScope = 'Auto';
BUS_double_log_t.Alignment = -1;
BUS_double_log_t.Elements = elems;
assigninContext('BUS_double_log_t',BUS_double_log_t)

%% single data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'v_gps_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'h_gps_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'heading_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'acc_x_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'acc_y_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'acc_z_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'p_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'q_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'r_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'phi_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'theta_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'psi_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'v_pitot_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dist_lidar_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'h_baro_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'press_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'temp_raw';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'h_baro_filt';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'ias_filt';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'RC_filt';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'groundspeed_filt';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'heading_filt';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dist_lidar_filt';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'single';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_single_log_t = Simulink.Bus;
BUS_single_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_single_log_t.DataScope = 'Auto';
BUS_single_log_t.Alignment = -1;
BUS_single_log_t.Elements = elems;
assigninContext('BUS_single_log_t',BUS_single_log_t)

%% int32 data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'dummy3';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int32';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dummy4';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int32';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_int32_log_t = Simulink.Bus;
BUS_int32_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_int32_log_t.DataScope = 'Auto';
BUS_int32_log_t.Alignment = -1;
BUS_int32_log_t.Elements = elems;
assigninContext('BUS_int32_log_t',BUS_int32_log_t)

%% uint32 data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'dummy5';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'uint32';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dummy6';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'uint32';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_uint32_log_t = Simulink.Bus;
BUS_uint32_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_uint32_log_t.DataScope = 'Auto';
BUS_uint32_log_t.Alignment = -1;
BUS_uint32_log_t.Elements = elems;
assigninContext('BUS_uint32_log_t',BUS_uint32_log_t)

%% int16 data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'manual_throttleCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'manual_elevatorCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'manual_aileronCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'manual_rudderCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'throttleCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'elevatorCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'aileronCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'rudderCmd_pwm';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_int16_log_t = Simulink.Bus;
BUS_int16_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_int16_log_t.DataScope = 'Auto';
BUS_int16_log_t.Alignment = -1;
BUS_int16_log_t.Elements = elems;
assigninContext('BUS_int16_log_t',BUS_int16_log_t)

%% uint16 data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'dummy9';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'uint16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dummy10';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'uint16';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_uint16_log_t = Simulink.Bus;
BUS_uint16_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_uint16_log_t.DataScope = 'Auto';
BUS_uint16_log_t.Alignment = -1;
BUS_uint16_log_t.Elements = elems;
assigninContext('BUS_uint16_log_t',BUS_uint16_log_t)

%% int8 data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'dummy11';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int8';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dummy12';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'int8';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_int8_log_t = Simulink.Bus;
BUS_int8_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_int8_log_t.DataScope = 'Auto';
BUS_int8_log_t.Alignment = -1;
BUS_int8_log_t.Elements = elems;
assigninContext('BUS_int8_log_t',BUS_int8_log_t)

%% uint8 data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'gps_fix';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'uint8';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dummy12';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'uint8';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_uint8_log_t = Simulink.Bus;
BUS_uint8_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_uint8_log_t.DataScope = 'Auto';
BUS_uint8_log_t.Alignment = -1;
BUS_uint8_log_t.Elements = elems;
assigninContext('BUS_uint8_log_t',BUS_uint8_log_t)

%% boolean data log bus definition
clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'dummy15';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'boolean';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('m');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'dummy16';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'boolean';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('round/s');
elems(end).Description = sprintf('');

BUS_bool_log_t = Simulink.Bus;
BUS_bool_log_t.Description = sprintf('double data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_bool_log_t.DataScope = 'Auto';
BUS_bool_log_t.Alignment = -1;
BUS_bool_log_t.Elements = elems;
assigninContext('BUS_bool_log_t',BUS_bool_log_t)

%% log bus definition (NON TOCCARE)

clear elems;

elems(1) = Simulink.BusElement;
elems(end).Name = 'double_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_double_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'single_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_single_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'int32_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_int32_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'uint32_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_uint32_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'int16_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_int16_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'uint16_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_uint16_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'int8_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_int8_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'uint8_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_uint8_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');

elems(end+1) = Simulink.BusElement;
elems(end).Name = 'bool_data';
elems(end).Dimensions = 1;
elems(end).DimensionsMode = 'Fixed';
elems(end).DataType = 'BUS_bool_log_t';
elems(end).SampleTime = -1;
elems(end).Complexity = 'real';
elems(end).SamplingMode = 'Sample based';
elems(end).Min = [];
elems(end).Max = [];
elems(end).DocUnits = sprintf('');
elems(end).Description = sprintf('');


BUS_log_t = Simulink.Bus;
BUS_log_t.Description = sprintf('data Log bus structure');
%BUS_log_t.HeaderFile = 'busLog_def.h';
BUS_log_t.DataScope = 'Auto';
BUS_log_t.Alignment = -1;
BUS_log_t.Elements = elems;
assigninContext('BUS_log_t',BUS_log_t)

%%



end