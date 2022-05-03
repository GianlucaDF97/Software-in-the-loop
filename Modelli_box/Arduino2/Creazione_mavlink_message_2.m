function [status,messaggio,messaggio_2,messaggio_3]  = Creazione_mavlink_message_2(byte_pack)


persistent Interr_parz  message counter len_found mess_len

if isempty(Interr_parz)
    Interr_parz = false ;
end
if isempty(message)
     message = uint8(zeros(1,100 )) ;
end
if isempty (counter) 
    counter = uint8(0) ;    % variabile che conta quanti byte mancano per completare il messaggio
end 

if isempty(len_found) 
     len_found = false ;
end 

if isempty(mess_len) 
     mess_len = false ;
end 

M = length(byte_pack) ;
caso = 0 ;
messaggio = uint8(zeros(1,100 )) ;
messaggio_2 = uint8(zeros(1,100 )) ;
messaggio_3 = uint8(zeros(1,100 )) ;
% LA VARIABILE INTERR_PARZ va attivata a 1 alla fine della funzone di
% lettura per indicare di leggere il successivo messaggio in arrivo 

[poss_254,num_254] = find_254(byte_pack) ;

if ( num_254 == 1 && Interr_parz == false )             
    caso = 1 ;                                                            % 1 Messaggio Intero   o parziale che inizia                % attivare alla fine della funzione Interr_parz == true o false 
elseif (num_254 == 0 && Interr_parz == true )
    caso = 2 ;                                                        % 1 Messaggio Parziale senza inizio e poi nulla 
elseif ( num_254 == 1 && Interr_parz == true  ) 
    caso = 3 ;                                                        % Continua mex prec. e hai un altro inizio
elseif ( num_254 == 2 && Interr_parz == true  ) 
    caso = 4 ;                                                         % Continua mex prec. e hai 2 altri inizi 
elseif ( num_254 == 3 && Interr_parz == true  ) 
    caso = 5 ;                                                         % Continua mex prec. e hai 3 altri inizi 
elseif  ( num_254 == 2 && Interr_parz == false ) 
    caso = 6 ;                                                         % Due messaggi completi  oppure 1 Completo + parziale ( attivare Interr_parz alla fine del codice)
elseif ( num_254 == 3 && Interr_parz == false ) 
    caso = 7 ;                                                          % 3 Messaggi Completi oppure 2 Completi + parziale    ( attivare Interr_parz alla fine del codice)
end


switch (caso)
    
    
    
    
    case 1 
        pos_254 = poss_254(num_254) ;
        
        if pos_254 == M                                                                          % se il 254 sta alla fine 
             message(1) = byte_pack(pos_254)  ;
            len_found = false ;
            Interr_parz = true ;
        else
             len = byte_pack(pos_254 + 1)  ;
             if ( M - ( pos_254) ) >= 7 + len                                             % se abbiamo tutto il messaggio all'interno del byte_pack
                message(1: 8 + len ) = byte_pack(pos_254 : pos_254 + (8+len) ) ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                counter = 0 ;
                len_found = true ;
                mess_len = 0 ;
             else
                mess_len = length(byte_pack(pos_254:end ) ) ;    % lunghezza del messaggio da leggere dal byte_pack ( non uguale alla lunghezza del messaggio complessivo)
                message(1 : mess_len) = byte_pack(pos_254:end ) ;
                len_found = true ;
                counter = 8 + len - mess_len ;
                Interr_parz = true ;
             end
             
        end

        
        
        
        
        
        
        
        
    case 2 
        
        if (len_found == false )              % se nel mex prec non c'era ancora la len del messaggio 
            len = byte_pack(1) ;
            if (len + 7) <= M      % se il parziale che abbiamo è tutto il messaggio rimanente 
                message(2 : len + 8 ) = byte_pack(1 : len + 7) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                len_found = true ;
                mess_len = 0 ;
            else                        % il parziale è ancora un parziale e il messaggio non è completo 
                message( 2 : (M + 1) )  = byte_pack(1:end) ;
                counter = 8 + len - (M + 1) ;
                Interr_parz = true ;
                len_found = true ;
            end
            
        else                                        % se la lunghezza è stata trovata e quindi ho il valore di counter che indica quante componenti mancano
            if counter <= M 
                message(mess_len + 1 : mess_len + counter) = byte_pack( 1 : counter) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                len_found = true ;
                mess_len = 0 ;
                counter = 0 ;
            else
                message(mess_len + 1 : mess_len + M   ) = byte_pack(1:end) ;
                Interr_parz = true ;
                len_found = true ;
                
            end
            
        end
        
        
        
        
        
        
        
        
        
        
        
    case 3 
            if (len_found == false )              % se nel mex prec non c'era ancora la len del messaggio 
                len = byte_pack(1) ;
                message(2 : len + 8 ) = byte_pack(1 : len + 7) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                counter = 0 ;
                mess_len = 0 ;
                %len_found = true ;
                    
            else                                                % se la lunghezza è stata trovata e quindi ho il valore di counter che indica quante componenti mancano
                message(mess_len + 1 : mess_len  + counter) = byte_pack( 1 : counter) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                %len_found = true ;
                mess_len = 0 ;
                counter = 0 ;
            end
            
            
        pos_254 = poss_254(num_254) ;
        
        if pos_254 == M                                                                          % se il 254 sta alla fine 
             message(1) = byte_pack(pos_254)  ;
            len_found = false ;
            Interr_parz = true ;
        else
             len = byte_pack(pos_254 + 1)  ;
             if ( M - ( pos_254) ) >= 7 + len                                             % se abbiamo tutto il messaggio all'interno del byte_pack
                message(1: 8 + len ) = byte_pack(pos_254 : pos_254 + (8+len) ) ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                counter = 0 ;
                len_found = true ;
                mess_len = 0 ;
             else
                mess_len = length(byte_pack(pos_254:end ) ) ;    % lunghezza del messaggio da leggere dal byte_pack ( non uguale alla lunghezza del messaggio complessivo)
                message(1 : mess_len) = byte_pack(pos_254:end ) ;
                len_found = true ;
                counter = 8 + len - mess_len ;
                Interr_parz = true ;
             end
             
        end
            
        
        
        
        
        
        
            
    case 4 
        
            if (len_found == false )              % se nel mex prec non c'era ancora la len del messaggio 
                len = byte_pack(1) ;
                message(2 : len + 8 ) = byte_pack(1 : len + 7) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                counter = 0 ;
                mess_len = 0 ;
                %len_found = true ;
                    
            else                                                % se la lunghezza è stata trovata e quindi ho il valore di counter che indica quante componenti mancano
                message(mess_len + 1 : mess_len  + counter) = byte_pack( 1 : counter) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                %len_found = true ;
                mess_len = 0 ;
                counter = 0 ;
            end
        primo_254 = poss_254(1) ;
        secondo_254 = poss_254(2) ;
        len_primo = byte_pack(primo_254 + 1) ;
        
        
        messaggio_2(1:len_primo + 8)  = byte_pack(primo_254 : secondo_254 - 1)  ;
        
        
        
        
        if secondo_254 == M                                                                          % se il 254 sta alla fine 
                 message(1) = byte_pack(secondo_254)  ;
                len_found = false ;
                Interr_parz = true ;
        else
                len = byte_pack(secondo_254 + 1)  ;
                mess_len = length(byte_pack(secondo_254:end ) ) ;    % lunghezza del messaggio da leggere dal byte_pack ( non uguale alla lunghezza del messaggio complessivo)
                message(1 : mess_len) = byte_pack(secondo_254:end ) ;
                len_found = true ;
                counter = 8 + len - mess_len ;
                Interr_parz = true ;
        end        
        
     
    case 5
        
        
            if (len_found == false )              % se nel mex prec non c'era ancora la len del messaggio 
                len = byte_pack(1) ;
                message(2 : len + 8 ) = byte_pack(1 : len + 7) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                counter = 0 ;
                mess_len = 0 ;
                %len_found = true ;
                    
            else                                                % se la lunghezza è stata trovata e quindi ho il valore di counter che indica quante componenti mancano
                message(mess_len + 1 : mess_len  + counter) = byte_pack( 1 : counter) ;
                Interr_parz = false ;
                messaggio = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                %len_found = true ;
                mess_len = 0 ;
                counter = 0 ;
            end
        primo_254 = poss_254(1) ;
        secondo_254 = poss_254(2) ;
        terzo_254 = poss_254(3) ;
        len_primo = byte_pack(primo_254 + 1) ;
        len_secondo = byte_pack(secondo_254 + 1);
        
        
        messaggio_2(1:  len_primo + 8)  = byte_pack(primo_254 : secondo_254 - 1)  ;
        messaggio_3(1 : len_secondo + 8) = byte_pack(secondo_254 : terzo_254 - 1 ) ;
        
        
         if   terzo_254 == M                                                                          % se il 254 sta alla fine 
                message(1) = byte_pack(terzo_254)  ;
                len_found = false ;
                Interr_parz = true ;
        else
                len = byte_pack(terzo_254 + 1)  ;
                mess_len = length(byte_pack(terzo_254 : end ) ) ;    % lunghezza del messaggio da leggere dal byte_pack ( non uguale alla lunghezza del messaggio complessivo)
                message(1 : mess_len) = byte_pack(terzo_254:end ) ;
                len_found = true ;
                counter = 8 + len - mess_len ;
                Interr_parz = true ;
        end                       
        
        
        
        
        
        
        
        
        
        
    case 6
        primo_254 = poss_254(1) ;
        secondo_254 = poss_254(2) ;
        len_primo = byte_pack(primo_254 + 1) ;
        messaggio(1 : len_primo + 8) = byte_pack(primo_254 : secondo_254 - 1 ) ;
        status = true ;
        
        
        if secondo_254 == M                                                                          % se il 254 sta alla fine 
             message(1) = byte_pack(secondo_254)  ;
            len_found = false ;
            Interr_parz = true ;
        else
             len = byte_pack(secondo_254 + 1)  ;
             if ( M - ( secondo_254) ) >= 7 + len                                             % se abbiamo tutto il messaggio all'interno del byte_pack
                message(1: 8 + len ) = byte_pack(secondo_254 : secondo_254 + (8+len) ) ;
                messaggio_2 = message ;
                status = true ;
                message = uint8(zeros(1,100 )) ;
                counter = 0 ;
                len_found = true ;
                mess_len = 0 ;
             else
                mess_len = length(byte_pack(secondo_254:end ) ) ;    % lunghezza del messaggio da leggere dal byte_pack ( non uguale alla lunghezza del messaggio complessivo)
                message(1 : mess_len) = byte_pack(secondo_254:end ) ;
                len_found = true ;
                counter = 8 + len - mess_len ;
                Interr_parz = true ;
             end
             
        end
        
        
    case 7
        
        primo_254 = poss_254(1) ;
        secondo_254 = poss_254(2) ;
        terzo_254 = poss_254(3) ;
        len_primo = byte_pack(primo_254 + 1) ;
        len_secondo = byte_pack(secondo_254 + 1);
        messaggio(1 : len_primo + 8) = byte_pack(primo_254 : secondo_254 - 1 ) ;   
        messaggio_2(1 : len_secondo + 8) = byte_pack(secondo_254 : terzo_254 - 1 ) ;
            
             if terzo_254 == M                                                                          % se il 254 sta alla fine 
             message(1) = byte_pack(secondo_254)  ;
            len_found = false ;
            Interr_parz = true ;
            else
             len = byte_pack(terzo_254 + 1)  ;
             if ( M - ( terzo_254) ) >= 7 + len                                             % se abbiamo tutto il messaggio all'interno del byte_pack
                message(1: 8 + len ) = byte_pack(terzo_254 : terzo_254 + (8+len) ) ;
                messaggio_3 = message ;
                message = uint8(zeros(1,100 )) ;
                counter = 0 ;
                len_found = true ;
                mess_len = 0 ;
             else
                mess_len = length(byte_pack(terzo_254:end ) ) ;    % lunghezza del messaggio da leggere dal byte_pack ( non uguale alla lunghezza del messaggio complessivo)
                message(1 : mess_len) = byte_pack(terzo_254:end ) ;
                len_found = true ;
                counter = 8 + len - mess_len ;
                Interr_parz = true ;
             end
             
             end 
            
end

end


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