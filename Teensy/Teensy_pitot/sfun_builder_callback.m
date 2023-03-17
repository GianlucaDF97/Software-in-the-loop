function sfun_builder_callback()
sfun_file_names = dir('*wrapper*');


clear mex

if ~isempty(sfun_file_names)
sfun_name = get_param(gcbh,'SFunctionModules');
sfun_name = strrep(sfun_name,' ','');
    for k=1:length(sfun_file_names)
        
        fid = fopen(sfun_file_names(k).name,'r');
        i = 1;
        tline = fgetl(fid);
        A{i} = tline;
        while ischar(tline)
            i = i+1;
            tline = fgetl(fid);
            A{i} = tline;
        end
        fclose(fid);

        
        A = A';
        
        A(find(cellfun(@(x)isempty(x),A)),1) = {' '};
        
        A = A(find(cellfun(@(x)ischar(x),A)));
        
        B = A;
        extC_found = cellfun(@(x)~isempty(strfind(x,'extern "C"')),A,'uni',false); %#ok<STREMP>
        if isempty(find(cell2mat(extC_found))) %#ok<EFIND>
            sfun_name = strrep(sfun_file_names(k).name,'.c','');
            wrapidx = strfind(sfun_name,'wrapper');
            func_names = {[sfun_name(1:wrapidx-1) 'Start_wrapper']; [sfun_name(1:wrapidx-1) 'Outputs_wrapper']; [sfun_name(1:wrapidx-1) 'Update_wrapper']; [sfun_name(1:wrapidx-1) 'Terminate_wrapper']};
            
            for i=1:length(func_names)
                func_found = cellfun(@(x)~isempty(strfind(x,func_names{i})),A,'uni',false); %#ok<*STREMP>
                if ~isempty(find(cell2mat(func_found)))
                    func_found_idx = find(cell2mat(func_found));
                    B{func_found_idx} = ['extern "C" ' B{func_found_idx}];
                end
            end
            
            
            fileID = fopen([pwd filesep 'sfunctions' filesep sfun_name '.cpp'],'w');
            fprintf(fileID,'%s\n',B{:});
            fclose(fileID);
            
            delete([sfun_name '.c']);
            list_file = dir(['*'  sfun_name(1:wrapidx-2) '*']);
            for j=1:length(list_file)
                movefile(list_file(j).name,[pwd filesep 'sfunctions'])
            end
        end
       clear A B 
    end
end
end