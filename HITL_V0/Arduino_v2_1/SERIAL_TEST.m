%%
close all; clear all; clc;

sett.port       = "COM8";
sett.baudrate	= 115200;
sett.byteorder	= "big-endian";

sett.SkipFactor             = 0xFFFF;                           % see pag. 41 of MT_Low_Level_Documentation.pdf
sett.header                 = 0xFA;
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
% write( device , sett.ReqDID , "uint8" );
pause( 1 );
if ( device.NumBytesAvailable > 0 )
%     message = device.NumBytesAvailable(5:1:52);
    % recupera tutto il buffer
    sms = read( device , device.NumBytesAvailable , "uint8" );
    sms_conv = reshape( [ dec2hex( sms )' ; ...
        repmat( ';' , 1 , length(sms) ) ] , 1 , [] );
    
    headers = strfind( sms_conv , dec2hex( sett.header ) );
    
    messages = cell( length( headers ) - 2 , 1 );
    
    for k = 1 : 1 : length( headers ) - 2
        
        messages{ k , 1 } = sms_conv( headers( k ) : 1 : headers( k + 1 ) - 2 );
        
        tmp = split( messages{ end } , ';' );
        typecast( hex2dec( tmp( 1 : 4)' )' , 'single' ) 
%         % converto il tipo (DA VERIFIARE)
%         sms_conv = typecast( sms , 'single' );
%         disp( sms_conv )
    end
    
else
    fprintf( '\n\n***\nNESSUN BYTE RICEVUTO!!!\n***\n\n' )
    
end




