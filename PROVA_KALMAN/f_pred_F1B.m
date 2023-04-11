function f = f_pred_F1B(prediction,a,dt)

%% Inizializzazione vettore


lat = prediction(1); long = prediction(2); h = prediction(3);

vn = prediction(4); ve = prediction(5); vd = prediction(6);

an = prediction(7); ae = prediction(8); ad = prediction(9);

p = prediction(10); q = prediction(11) ; r = prediction(12);

baccx = prediction(13); baccy = prediction(14); baccz = prediction(15);

bp = prediction(16); bq = prediction(17); br = prediction(18); 

%% Equazioni transizione di stato


  f=[  
      
    lat + (dt*vn)/(a + h);
    long + dt*ve/(cos(lat)*(a + h));
    h - dt*vd; % h - dt*vd-ad*0.5*dt^2

    vn + an*dt;
    ve + ae*dt;
    vd + ad*dt;

    an;
    ae;
    ad;

    p;
    q;
    r;

    baccx;
    baccy;
    baccz;

    bp;
    bq;
    br];
end

