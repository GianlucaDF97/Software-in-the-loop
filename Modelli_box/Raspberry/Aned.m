function Acc_ned_out = Aned(acc_x,acc_y,acc_z,phi,theta,psi)

 LBE =[cos(theta)*cos(psi) cos(theta)*sin(psi) -sin(theta);
    sin(phi)*sin(theta)*cos(psi)-cos(phi)*sin(psi) sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi) sin(phi)*cos(theta);
    cos(phi)*sin(theta)*cos(psi)+sin(phi)*sin(psi) cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi) cos(phi)*cos(theta)];


Acc_body = [acc_x,acc_y,acc_z]; 

Acc_ned = LBE.'*Acc_body.';
Acc_ned(3)=Acc_ned(3);

Acc_ned_out=Acc_ned;
