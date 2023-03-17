function F = jac_F_F1B(prediction,a,dt)

%% Inizializzazione vettore


lat = prediction(1); long = prediction(2); h = prediction(3);

vn = prediction(4); ve = prediction(5); vd = prediction(6);

an = prediction(7); ae = prediction(8); ad = prediction(9);

p = prediction(10); q = prediction(11) ; r = prediction(12);

baccx = prediction(13); baccy = prediction(14); baccz = prediction(15);

bp = prediction(16); bq = prediction(17); br = prediction(18); 

%% Jacobiano equazioni di stato



F=[                                     1, 0,            -(dt*vn)/(a + h)^2, dt/(a + h),                     0,   0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
 (dt*ve*sin(lat))/(cos(lat)^2*(a + h)), 1, -(dt*ve)/(cos(lat)*(a + h)^2),          0, dt/(cos(lat)*(a + h)),   0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                     0, 0,                             1,          0,                     0, -dt,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                    0, 0,                             0,          1,                     0,   0, dt,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     1,   0,  0, dt,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     0,   1,  0,  0, dt, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     0,   0,  1,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     0,   0,  0,  1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                    0, 0,                             0,          0,                     0,   0,  0,  0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0;
                                    0, 0,                             0,          0,                     0,   0,  0,  0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0;
                                    0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0;
                                     0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0;
                                    0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0;
                                     0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0;
                                    0, 0,                             0,          0,                     0,   0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1];
 
%  F(3,12)=-dt^2*0.5;                              
end

