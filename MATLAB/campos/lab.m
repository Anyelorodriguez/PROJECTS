clear all
close all 
clc
    r= 2;
    f=0;
    for i=-15:15
        dx=1;
        x=i*dx;
        if -1<x<3
            for h=0:13
                y=(((r).^2-(x).^2)^0.5)+h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;

                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                         
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;    
            end
            for h=-13:0
                y=-(((r).^2-(x).^2)^0.5)+h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;

                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                         
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;    
            end
        elseif -3<x<0
            for h=0:13
                y=(((r).^2-(x).^2)^0.5)+h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;

                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                         
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;    
            end
            for h=-13:0
                y=-(((r).^2-(x).^2)^0.5)+h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;
                    
                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                         
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;    
            end
        elseif -16<x<-2
            for h=0:15
                y=h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;

                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                                
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;
            end
            for h=-15:0
                y=h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;

                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                                
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;
            end
        else
            for h=0:15
                y=h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;

                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                                
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;
            end
            for h=-15:0
                y=h;
                for c=1:1000
                    t=(2*pi*c)/(1000);
                    a= ((x.^2)+(y.^2)).^(0.5);
                    k = 2.*r.*a;

                    x1 = ((8.99.*(10.^9)).*r)./(((r).^2+(a).^2+k.*cos(t)).^(0.5));
                    f=f+x1;
                                
                end
            fprintf('\n\n\n');
            disp(x);
            disp(y);
            fprintf('   %s \n',f);
            f=0;
            end
       end
    end;