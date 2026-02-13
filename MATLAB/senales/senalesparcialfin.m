syms x t X w;

x=21/(t^2+28);
f=(exp(1i*w*t));

fx1 =(int(x*f));

fprintf("\n  A=%s",fx1);