clear all
s = serialport('COM18',115200)
write(s,[250 255 16 0 208], 'uint8');
Messagestorage = zeros(100,54);
StatusWrong= [];
for i=1:100
    Messagestorage(i,:) = read(s,54,'uint8');
    if Messagestorage(i,53) ~= 3
        i = StatusWrong(end);
    end
end
Messageuse = zeros(100,9);
% if StatusWrong
%     for i=1:length(StatusWrong)
%         Messageuse(i,:)=[];
%     end
% end
% for i=1:size(Messageuse(:,1))
accx = dec2bin( Messagestorage(5,5:8) ) ;
accX = [accx(1,:) accx(2,:) accx(3,:) accx(4,:)]
accy = dec2bin( Messagestorage(5,9:12) ) ;
accY = [accy(1,:) accy(2,:) accy(3,:) accy(4,:)];
accz = dec2bin( Messagestorage(5,13:16) ) ;
accZ = [accz(1,:) accz(2,:) accz(3,:) accz(4,:)];
pvel = dec2bin( Messagestorage(5,17:20) ) ;
p    = [pvel(1,:) pvel(2,:) pvel(3,:) pvel(4,:)];
qvel = dec2bin( Messagestorage(5,21:24) ) ;
q    = [qvel(1,:) qvel(2,:) qvel(3,:) qvel(4,:)];
rvel = dec2bin( Messagestorage(5,25:28) ) ;
r    = [rvel(1,:) rvel(2,:) rvel(3,:) rvel(4,:)];
phi  = dec2bin( Messagestorage(5,41:44) ) ;
Phi  = [phi(1,:) phi(2,:) phi(3,:) phi(4,:)];
th   = dec2bin( Messagestorage(5,45:48) ) ;
Th   = [th(1,:) th(2,:) th(3,:) th(4,:)];
psi  = dec2bin( Messagestorage(5,49:52) ) ;
Psi  = [psi(1,:) psi(2,:) psi(3,:) psi(4,:)];
% end










