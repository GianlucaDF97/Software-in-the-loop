function [position,counter] = find_254(pack) 
    position = zeros(1,3) ;
    M = length(pack)  ;   
    counter = 0 ;
    for i = 1 : M
        if pack(i) == 254 
            counter = counter + 1 ; 
            position(counter) = i ;
        end
    end
end