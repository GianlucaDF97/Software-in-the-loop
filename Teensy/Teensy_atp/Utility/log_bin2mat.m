function log_bin2mat()

% clear all
basePath = evalin('base','basePath');
[file,path] = uigetfile('*.bin');
fid = fopen(fullfile(path,file) ,'r');
dataRaw = fread(fid);
fclose(fid);

fid = fopen([basePath '\sfunctions\Signal_Logger_sfun_bus.h'],'r');

i = 1;
tline = fgetl(fid);
A{i} = tline;
while ischar(tline)
    i = i+1;
    tline = fgetl(fid);
    A{i} = tline;
end
fclose(fid);

bustype = {'BUS_double_log_t',...
    'BUS_single_log_t',...
    'BUS_int32_log_t',...
    'BUS_uint32_log_t',...
    'BUS_int16_log_t',...
    'BUS_uint16_log_t',...
    'BUS_int8_log_t',...
    'BUS_uint8_log_t',...
    'BUS_bool_log_t',...
    'BUS_log_t'};

A = A';

braket_idx = find(cell2mat(cellfun(@(x) ~isempty(strfind(x,'{'))|~isempty(strfind(x,'}')),A,'uni',false)));

k = 1;
for i=2:2:length(braket_idx)
    
    bustype_inc = strrep(A(braket_idx(i)),' ','');
    bustype_inc = strrep(bustype_inc,'}','');
    bustype_inc = strrep(bustype_inc,';','');
    
    cellA = cellfun(@strsplit,A(braket_idx(i-1)+1:braket_idx(i)-1),'uni',false );
    
    for j=1:numel(cellA)
        cellA{j}(1) = [];  %rimuovo la cella vuota
        cellA{j}{2} = strrep(cellA{j}{2},';','');
    end
    
    structToInc{k,1} = {bustype_inc,cellA} ;

    k=k+1;
     
end

structToInc = vertcat(structToInc{:});

for k=1:length(bustype)-1
    type_idx = find(cell2mat(cellfun(@(x) any(strcmp(x,bustype(k))),structToInc,'uni',false)));
    for j=1:numel(structToInc{type_idx,2})
        if k==1 && j==1
            [flag,bitsnum_tmp,struct_data_t_tmp,name_tmp] = check_bus(structToInc,type_idx,j);
            if flag
                bitsnum(1) = bitsnum_tmp;
                struct_data_t(1) = struct_data_t_tmp;
                name{1} = name_tmp;
            else
                errordlg('ce qualche problema');
            end
            
            
        else
            [flag,bitsnum_tmp,struct_data_t_tmp,name_tmp] = check_bus(structToInc,type_idx,j);
            if flag
                
                bitsnum(end+1) = bitsnum_tmp;
                struct_data_t(end+1) = struct_data_t_tmp;
                name{end+1} = name_tmp;
                
                
            else
                
                busToInc_idx  = find(cell2mat(cellfun(@(x) any(strcmp(x,structToInc{type_idx,2}{j}{1})),structToInc,'uni',false)));
                for p=1:numel(structToInc{busToInc_idx,2})
                    [flag,bitsnum_tmp,struct_data_t_tmp,name_tmp] = check_bus(structToInc,busToInc_idx,p);
                    if flag
                        
                        bitsnum(end+1) = bitsnum_tmp;
                        struct_data_t(end+1) = struct_data_t_tmp;
                        name{end+1} = name_tmp;
                    else
                        
                        errordlg('cé un bus contenente altri bus, questo caso non é ancora coperto');
                        
                    end
                end
            end 
        end
    end  
end


packet_idx = find(ismember(dataRaw, char(13)));

base = (sum(bitsnum)/8)/(max(bitsnum)/8);

if mod((sum(bitsnum)/8),(max(bitsnum)/8)) ~= 0
    packet_len = (fix(base)+1)*(max(bitsnum)/8);
else
    packet_len = (fix(base))*(max(bitsnum)/8);
end



flag = false;

pp =2;
p=1;
while pp<=length(packet_idx)
    
    if abs(packet_idx(pp)-packet_idx(p)) == packet_len+1
        if p == 1
            
            if flag
                packet_idx_tmp(p) = packet_idx(p);
                p=pp;
                pp=pp+1;
                flag = false;
            else
                packet_idx_tmp(p) = packet_idx(p);
                p=p+1;
                pp=pp+1;
            end
        else
            if flag
                packet_idx_tmp(end+1) = packet_idx(p);
                p=pp;
                pp=pp+1;
                flag = false;
            else
                packet_idx_tmp(end+1) = packet_idx(p);
                p=p+1;
                pp=pp+1;
            end
        end
    else
        pp=pp+1;
        flag = true;
    end
    
end
if exist('packet_idx_tmp','var')
    packet_idx = packet_idx_tmp;
end

for j=1:length(packet_idx)
    prev_idx = 0;
    bitcount = 0;
    for k=1:length(bitsnum)
        if j == 1
            switch struct_data_t{k}
                case 'double'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''double'');']);
                case 'float'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''single'');']);
                case 'int32'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''int32'');']);
                case 'uint32'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''uint32'');']);
                case 'int16'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''int16'');']);
                case 'uint16'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''uint16'');']);
                case 'int8'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''int8'');']);
                case 'uint8'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''uint8'');']);
                case 'bool'
                    eval(['dataLog_tmp.' name{k} '(j)=cast(uint8(dataRaw(prev_idx+1:prev_idx+bitsnum(k)/8)),''logical'');']);
            end
            prev_idx = prev_idx+bitsnum(k)/8;
        else
            
            switch struct_data_t{k}
                case 'double'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''double'');']);
                case 'float'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''single'');']);
                case 'int32'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''int32'');']);
                case 'uint32'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''uint32'');']);
                case 'int16'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''int16'');']);
                case 'uint16'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''uint16'');']);
                case 'int8'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''int8'');']);
                case 'uint8'
                    eval(['dataLog_tmp.' name{k} '(j)=typecast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''uint8'');']);
                case 'bool'
                    eval(['dataLog_tmp.' name{k} '(j)=cast(uint8(dataRaw(packet_idx(j-1)+prev_idx+1:prev_idx+packet_idx(j-1)+bitsnum(k)/8)),''logical'');']);
            end
            prev_idx = prev_idx+bitsnum(k)/8;
            
        end
        
        
        
    end
end
for k=1:length(name)
    if k==1
        eval(['dataLog.' name{k} '=dataLog_tmp.time_frame;']);
    else
        eval(['dataLog.' name{k} '=timeseries(dataLog_tmp.' name{k} ',dataLog_tmp.time_frame,''Name'',''' name{k} ''');']);
    end
end

date = datestr(datetime);
date = strrep(date,' ','_');
date = strrep(date,':','_');
date = strrep(date,'-','_');
save([basePath '\DataLog\FlightData_' date '.mat'],'dataLog');
end

function [flag,bitsnum,struct_data_t,name] = check_bus(structToInc,type_idx,j)
flag = 1;
if contains(structToInc{type_idx,2}{j}{1},'real_T')
    
    bitsnum = 64;
    struct_data_t = {'double'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'real32_T')
    
    bitsnum = 32;
    struct_data_t = {'float'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'int32_T')
    
    bitsnum = 32;
    struct_data_t = {'int32'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'uint32_T')
    
    bitsnum = 32;
    struct_data_t = {'uint32'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'int16_T')
    
    bitsnum = 16;
    struct_data_t = {'int16'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'uint16_T')
    
    bitsnum = 16;
    struct_data_t = {'uint16'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'int8_T')
    
    bitsnum = 8;
    struct_data_t = {'int8'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'uint8_T')
    
    bitsnum = 8;
    struct_data_t = {'uint8'};
    name = structToInc{type_idx,2}{j}{2};
    
elseif contains(structToInc{type_idx,2}{j}{1},'boolean_T')
    
    bitsnum = 8;
    struct_data_t = {'bool'};
    name = structToInc{type_idx,2}{j}{2};
else
    flag = 0;
    bitsnum = 0;
    struct_data_t = {''};
    name = '';
    
end


end