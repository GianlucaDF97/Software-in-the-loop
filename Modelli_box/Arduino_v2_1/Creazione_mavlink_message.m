function [status,messaggio,len]  = Creazione_mavlink_message(byte_pack)

persistent message start_found len_found counter 

len = 0 ;
if isempty(message)
     message = uint8(zeros(1,100 )) ;
end
if isempty(start_found) 
     start_found = false ;
end 
if isempty(len_found) 
     len_found = false ;
end 
if isempty (counter) 
    counter = uint8(0) ;
end 

M = uint8(length(byte_pack)) ;



if start_found == false 
    for i = uint8(1) : M  
        if byte_pack(i) == 254 
            
            start_found = true ;
            if i < M 
                len = byte_pack( i +1) ;
                len_found = true ;                      % per far capire che nel messaggio seguente ci sarà la len del messaggio 
                in =  i + 7 + len ;                          
                if  in  <= M                                    % caso in cui abbiamo tutto il messaggio in un pacchetto 
                    message( 1 : 8 + len ) = byte_pack(i : in +1 ) ;
                    messaggio = message  ;
                    start_found = false ;
                    
                else                                                  % caso in cui non c' è tutto in un pacchetto
                    message(1 : (M - (i - 1)) ) = byte_pack(i:end) ;
                    counter = M - (i-1) ;
                end
                
            else
                break
            end
            
        end
    end
    
    
elseif start_found == true
    
    avanzo = len + 8 - counter ;
    if avanzo <=M           % se nel byte_pack ci sono tutti i byte necessari più quelli dell'altro messaggio 
        message( counter + 1 : avanzo + counter ) = byte_pack(1 : avanzo) ;
        
    else 
        message (counter + 1 : avanzo + counter ) = byte_pack(1:end) ;
    counter = counter + ;
    
    
    
    end
    
    
end



end
           
            
            