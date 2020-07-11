#include "wall.h"

wall::wall(int player, int round, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setZValue(2);
    if (player == 1){
        for(int y = 100; y <= 750; y += 50){
            for(int x = 0; x <= 1150;  ){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(y == 100 || y == 750){
                    x += 50;
                }
                else {
                    x += 1150;
                }
            }
        }
        if(round == 2){
            for(int y = 150; y <=200; y+=50){
                for(int x = 150; x <= 1050;){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    if(x == 150){
                        x+=350;
                    }
                    else if(x == 800){
                        x+=250;
                    }
                    else{
                        x+=300;
                    }
                }
            }
            for(int x = 350, y = 250; x <= 900;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 350){
                    x+=350;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 150, y = 300; x <= 800;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 150){
                    x+=200;
                }
                else{
                    x+=450;
                }
            }
            for(int x = 150, y = 350; x <= 1000;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 150){
                    x+=200;
                }
                else if(x == 550){
                    x+=250;
                }
                else if(x == 800){
                    x+=100;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 100, y = 400; x <= 550;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 150){
                    x+=400;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 50, y = 450; x <= 550;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 100){
                    x+=250;
                }
                else if (x == 350) {
                    x += 200;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 200, y = 500; x <= 900;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 200 || x == 400){
                    x+=150;
                }
                else if( x == 700){
                    x+=200;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 100, y = 550; x <= 1000;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 200 || x == 700){
                    x+=200;
                }
                else if( x == 450){
                    x+=250;
                }
                else if( x == 900){
                    x+=100;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 100, y = 600; x <= 1050;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 100){
                    x+=350;
                }
                else if( x == 500){
                    x+=200;
                }
                else if( x == 800 || x == 900){
                    x+=100;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 100, y = 650; x <= 900;){
                brick *newwall;
                newwall = new brick(x,y,this);
                if(x == 100){
                    x+=100;
                }
                else if( x == 250){
                    x+=650;
                }
                else{
                    x+=50;
                }
            }
            for(int x = 250, y = 700; x <= 900;x += 650){
                brick *newwall;
                newwall = new brick(x,y,this);
            }










        }
        if(round == 3){
            //2,-2
            for(int y = 150; y <=700; y+=550){
                for(int x = 250, k = 750; x <= 400 && k<= 900; x+=50, k+=50){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);

                }
            }
            //3,-3
            for(int y = 200; y <=650; y+=450){
                for(int x = 100, k = 1050; x <= 250 && k>= 900; x+=150, k-=150){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);

                }
            }
            //4,-4
            for(int y = 250; y <=600; y+=350){
                for(int x = 250, k = 900; x <= 450 && k>= 700;){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 250 && k == 900){
                        x+=100;
                        k-=100;
                    }
                    else{
                        x+=50;
                        k-=50;
                    }
                }
            }
            //5,-5
            for(int y = 300; y <=550; y+=250){
                for(int x = 50, k = 1100; x <= 350 && k>= 800;){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 100 && k == 1050){
                        x+=250;
                        k-=250;
                    }
                    else{
                        x+=50;
                        k-=50;
                    }
                }
            }
            //6,-6
            for(int y = 350; y <=500; y+=150){
                for(int x = 200, k = 950; x <= 550 && k>= 600; ){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 350 && k == 800){
                        x+=200;
                        k-=200;
                    }
                    else{
                        x+=150;
                        k-=150;
                    }
                }
            }
            //7,-7
            for(int y = 400; y <=450; y+=50){
                for(int x = 150, k = 1000; x <= 550 && k>= 600; ){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 200 && k == 950){
                        x+=300;
                        k-=300;
                    }
                    else{
                        x+=50;
                        k-=50;
                    }
                }
            }

        }
    }
    else if(player == 2){
        if (round == 1){
            for(int y = 0; y <= 750; y += 50){
                for(int x = 0; x <= 1150;  ){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    if(y == 0 || y == 750){
                        x += 50;
                    }
                    else {
                        x += 1150;
                    }
                }
            }
            //2,-2
            for(int y = 150; y <=700; y+=550){
                for(int x = 250, k = 750; x <= 400 && k<= 900; x+=50, k+=50){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);

                }
            }
            //3,-3
            for(int y = 200; y <=650; y+=450){
                for(int x = 100, k = 1050; x <= 250 && k>= 900; x+=150, k-=50){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);

                }
            }
            //4,-4
            for(int y = 250; y <=600; y+=350){
                for(int x = 250, k = 900; x <= 450 && k>= 700;){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 250 && k == 900){
                        x+=100;
                        k-=100;
                    }
                    else{
                        x+=50;
                        k+=50;
                    }
                }
            }
            //5,-5
            for(int y = 300; y <=550; y+=250){
                for(int x = 50, k = 1100; x <= 350 && k>= 800;){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 100 && k == 1050){
                        x+=250;
                        k-=250;
                    }
                    else{
                        x+=50;
                        k+=50;
                    }
                }
            }
            //6,-6
            for(int y = 350; y <=500; y+=150){
                for(int x = 200, k = 950; x <= 550 && k>= 600; ){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 350 && k == 800){
                        x+=150;
                        k-=150;
                    }
                    else{
                        x+=200;
                        k+=200;
                    }
                }
            }
            //7,-7
            for(int y = 400; y <=450; y+=50){
                for(int x = 150, k = 1000; x <= 550 && k>= 600; ){
                    brick *newwall;
                    newwall = new brick(x,y,this);
                    brick *dnewwall;
                    dnewwall = new brick(k,y,this);
                    if(x == 200 && k == 950){
                        x+=300;
                        k-=300;
                    }
                    else{
                        x+=50;
                        k+=50;
                    }
                }
            }

        }
        else if (round == 2) {

        }
        else if (round == 3 ){

        }
    }
}
