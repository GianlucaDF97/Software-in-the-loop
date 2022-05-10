%%
close all; clear all; clc;

sett.port       = "COM13";
sett.baudrate	= 38400;
sett.byteorder	= "big-endian";

sett.SkipFactor             = 0xFFFF;                           % see pag. 41 of MT_Low_Level_Documentation.pdf
sett.header                 = [ 0xFA, 0xFF, 0x32, 0x31 ];
sett.ReqDID                 = [ 0xFA 0xFF 0x00 0x00 0x01 ];
sett.ReqOutputMode          = [ 0xFA 0xFF 0xD0 0x00 0x31 ];
sett.ReqData                = [ 0xFA 0x01 0x34 0x00 0xCB ];
sett.GoToMeasurement        = [ 0xFA 0xFF 0x10 0x00 0xF1 ];
% DA VERIFICARE IL CHECKSUM. I MESSAGGI SONO CISI' SCRITTI SONO INCORRETTI
% sett.ReqOutputSkipFactor    = [ 0xFA 0xFF 0xD4 0x00 0x01 ];     % see pag. 40 of MT_Low_Level_Documentation.pdf
% sett.ReqPortConfig          = [ 0xFA 0xFF 0x8C 0x00 0xE9 ];
% sett.WakeUp                 = [ 0xFA 0xFF 0x3E 0x00 0xE9 ];
% sett.GoToConfig             = [ 0xFA 0xFF 0x30 0x00 0xE9 ];
% sett.GoToMeasurement        = [ 0xFA 0xFF 0x10 0x00 0xE9 ];
% sett.ReqMTData              = [ ];

%%
fprintf( '\nApertura collegamento seriale su: %s -> ' , sett.port );
device = serialport( sett.port , sett.baudrate );
fprintf( '[ OK ]\n' );

%%
% see 5.1.1 Big endian output format on pag. 14 of MT_Low_Level_Documentation.pdf
fprintf( 'Imposto il ByteOrder a: %s -> ' , sett.byteorder );
device.ByteOrder = sett.byteorder;
fprintf( '[ OK ]\n\n' );
disp( device )

%%
fprintf( 'Richiedo le misure: -> ' );
write( device , sett.GoToMeasurement , "uint8" );
fprintf( '[ OK ]\n\n' );
disp( device )

%%

% esempio di comunicazione
pause(1)


if ( device.NumBytesAvailable > 0 )
    % recupera tutto il buffer
    sms = read( device , device.NumBytesAvailable , "uint8" );
    
    headers_count = 0;
    header_pos = 0;
    count = 1;
    
    % ciclo sui bytes ricevuti
    for k = 4 : 1 : numel(sms)
        
        % individuo l'header del messaggio
        if (isequal(uint8(sms(k-3)),sett.header(1)))&& ...
                (isequal(uint8(sms(k-2)),sett.header(2))) && ...
                (isequal(uint8(sms(k-1)),sett.header(3))) && ...
                (isequal(uint8(sms(k-0)),sett.header(4)))
            
            % incremento gli header trovati
            headers_count=headers_count+1;
            
            % memorizzo la posizione dell'header individuata partendo dal
            % vettore dei bytes ricevuti
            header_pos(count) = k-3;
            
            % incremento il contatore posizionale
            count=count+1;
        end
        
    end
    
    fprintf( '\n\n%-40s: %d\n', 'Bytes ricevuti', numel(sms) );
    fprintf( '%-40s: %d\n', 'Posizione del primo header', header_pos(1) );
    fprintf( '%-40s: %d\n', 'Messaggi individuati', headers_count );
    fprintf( '%-40s: %d\n', 'Lunghezza media dei messaggi ricevuti', mean(diff(header_pos)) );
    if (numel(header_pos)>10)
        fprintf( '-----------------------------\n' );
        for m=1:1:10
            fprintf( '%-40s: %s\n', strcat('Messaggio num. ' ,num2str(m)), num2str(sms(header_pos(m):1:header_pos(m+1)-1)) );
        end
        fprintf( '-----------------------------\n\n\n' );
        
    end
else
    fprintf( '\n\n***\nNESSUN BYTE RICEVUTO!!!\n***\n\n' )
end




