function Aenea_CodeGen()

basePath = evalin('base','basePath');
cd(basePath);
rtwbuild('Aenea_model')
load('Aenea_model_teensy_ec_rtw\buildInfo.mat');
packNGo(buildInfo,'packType', 'flat','fileName','Aenea_Teensy_code');
unzip('Aenea_Teensy_code.zip','Aenea_Teensy_code')
movefile Aenea_Teensy_code/ert_main.cpp Aenea_Teensy_code/Aenea_Teensy_code.ino
delete 'Aenea_Teensy_code/defines.txt'
delete 'Aenea_Teensy_code.zip'
zip('Aenea_Teensy_code.zip','Aenea_Teensy_code')
rmdir Aenea_Teensy_code s

end