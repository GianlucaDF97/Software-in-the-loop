function Aenea_CodeGen()

basePath = evalin('base','basePath');
cd(basePath);
rtwbuild('Aenea_model')
load('Aenea_model_teensy_ec_rtw\buildInfo.mat');
folderToInclude = {'src',...
    'src/include',...
    'src/include/ardupilotmega',...
    'src/include/common',...
    'src/include/icarous',...
    'src/include/uAvionix'};
for i=1:numel(folderToInclude)
    addIncludeFiles(buildInfo,'*.h', folderToInclude{i} , 'HFiles');
end


packNGo(buildInfo,'packType', 'flat','fileName','Aenea_Teensy_code');
unzip('Aenea_Teensy_code.zip','Aenea_Teensy_code')
movefile Aenea_Teensy_code/ert_main.cpp Aenea_Teensy_code/Aenea_Teensy_code.ino
copyfile pwm_libraries/calcInputThrottle.c Aenea_Teensy_code
copyfile pwm_libraries/calcInputAileron.c Aenea_Teensy_code
copyfile pwm_libraries/calcInputElevator.c Aenea_Teensy_code
copyfile pwm_libraries/calcInputRudder.c Aenea_Teensy_code
copyfile pwm_libraries/calcInput_go_Home.c Aenea_Teensy_code
delete 'Aenea_Teensy_code/defines.txt'
delete 'Aenea_Teensy_code.zip'

% src_h_files = dir('Aenea_Teensy_code/src/*.h');
% h_files = dir('Aenea_Teensy_code/*.h');
% cpp_files = dir('Aenea_Teensy_code/*.cpp');
% c_files = dir('Aenea_Teensy_code/*.c');
% 
% hc_files = [h_files; cpp_files; c_files];
% 
% for k=1:length(hc_files)
%
%     fid = fopen(['Aenea_Teensy_code/' hc_files(k).name],'r');
%     i = 1;
%     tline = fgetl(fid);
%     A{i} = tline;
%     while ischar(tline)
%         i = i+1;
%         tline = fgetl(fid);
%         A{i} = tline;
%     end
%     fclose(fid);
%
%
%     A = A';
%
%     A(find(cellfun(@(x)isempty(x),A)),1) = {' '};
%
%     A = A(find(cellfun(@(x)ischar(x),A)));
%
%     for m=1:length(src_h_files)
%
%         if any(cell2mat(cellfun(@(x)~isempty(strfind(x,src_h_files(m).name)),A,'uni',false)))
%
%             repidx = find(cell2mat(cellfun(@(x)~isempty(strfind(x,src_h_files(m).name)),A,'uni',false)));
%
%             for r=1:length(repidx)
%                 A{repidx} = strrep(A{repidx},src_h_files(m).name,['src/' src_h_files(m).name]);
%             end
%
%             fileID = fopen(['Aenea_Teensy_code/' hc_files(k).name],'w');
%             fprintf(fileID,'%s\n',A{:});
%             fclose(fileID);
%
%         end
%     end
%     clear A
% end

zip('Aenea_Teensy_code.zip','Aenea_Teensy_code')
rmdir Aenea_Teensy_code s

end