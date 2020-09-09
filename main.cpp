#include <SFML/Graphics.hpp>///use it for graphics
#include <SFML/Audio.hpp>///use it for sound and music
#include<sstream>
#include<ctime>
#include<iostream>
#include<windows.h>
#include "Menu.h"
#include <iomanip>
#include <locale>
#include<fstream>

using namespace sf;
using namespace std;

string s(double n);

int main()
{
b:
    int tab=0,flag=0;
    RenderWindow start(VideoMode(800,800),"Fahim && Shakil ");////
    //////////creating menu//
    sf::Texture menu_tex;
    if(!menu_tex.loadFromFile("menu.jpg"))
    {
        cout<<"Menu Image Loading Failed"<<endl;
        return -1;

    }
    sf::RectangleShape menu;
    menu.setSize(Vector2f(800,800));
    menu.setPosition(0, 0);
    menu.setTexture(&menu_tex);
    /////////
    sf::RectangleShape rect(Vector2f(300,100));
    rect.setPosition(250,55);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(20);
https:
    ///sounds////////
    SoundBuffer buffer;
    if(!buffer.loadFromFile("s.ogg"))
    {
        printf("Error");
    }
    //////
    Sound hit;
    hit.setBuffer(buffer);
    hit.setVolume(300);
    //////
    /////::::::::::::::setting texture for music/////
    sf::Texture music_tex;
    if(!music_tex.loadFromFile("music.jpg"))
    {
        cout<<"Music Front Image Loading Failed"<<endl;
        return -1;
    }
    RectangleShape music_front;
    music_front.setSize(Vector2f(800, 800));
    music_front.setPosition(0, 0);
    music_front.setTexture(&music_tex);
    //////////////
    sf::Texture highscore_tex;
    if(!highscore_tex.loadFromFile("highscore.jpg"))
    {
        cout<<"Highscore Front Image Loading Failed"<<endl;
        return -1;
    }
    RectangleShape highscore_front;
    highscore_front.setSize(Vector2f(800, 800));
    highscore_front.setPosition(0, 0);
    highscore_front.setTexture(&highscore_tex);

    ///High score
    double hscore;

    ifstream read;
    read.open("high score.txt");
    ///check for error
    if(read.fail())
    {
        cout<<"Text File Loading Failed"<<endl;
        exit(1);
    }
    if(read.is_open())
    {
        read >> hscore;
    }
    read.close();

    cout<<"high score : "<<hscore<<endl;

    ///load font from file
    Font myfont;
    Text myscore;
    Text mylive;
    Text mylevel;
    Text myhigh;
    Text press;
    Text text1;
    Text text2;
    Text text3;
    Text text4;
    Text text5;
    Text text6;
    ///// bool playButton = false;
    myfont.loadFromFile("shakil123.ttf");

    Text hs_score;
    hs_score.setFont(myfont);
    hs_score.setCharacterSize(30);
    hs_score.setFillColor(Color::Black);
    hs_score.setPosition(Vector2f(200, 200));

    ////////////
    //////Music
    Music music;///open music for car racing/
    if(!music.openFromFile("carsound.ogg"))
    {
        printf("Error");
    }
    music.setLoop(true);
    music.setVolume(100);
    music.play();

    int music_Button=0, crash_sound = 1,highscore=0;

    //////
    while(start.isOpen())///open window for start menu
    {

        Event event;
        while(start.pollEvent(event))
        {

            if(rect.getPosition().y==55 && Keyboard::isKeyPressed(Keyboard::Enter))
                start.close();
            if(rect.getPosition().y<580 && music_Button == 0)
            {
                if( Keyboard::isKeyPressed(Keyboard::Down))
                    rect.setPosition(rect.getPosition().x,rect.getPosition().y+175);
            }

            if(rect.getPosition().y>55 && music_Button == 0)
                if( Keyboard::isKeyPressed(Keyboard::Up))
                    rect.setPosition(rect.getPosition().x,rect.getPosition().y-175);
            ///::::::::::::High score Button
            if(rect.getPosition().y==230 && Keyboard::isKeyPressed(Keyboard::Enter))
            {
                highscore=1;
                rect.setPosition(0,0);
                rect.setSize(Vector2f(0,0));
                menu.setPosition(2000, 2000);
                music_front.setPosition(2000, 2000);
                highscore_front.setPosition(0,0);


            }
            if(highscore == 1)
            {
                hs_score.setPosition(Vector2f(310, 270));

                stringstream text;
                text<<hscore;
                hs_score.setString(text.str());

            }
            if(highscore == 1&& Keyboard::isKeyPressed(Keyboard::BackSpace))
            {
                music_front.setPosition(2000, 2000);
                highscore_front.setPosition(2000, 2000);
                rect.setPosition(250,55);
                rect.setSize(Vector2f(300,100));
                menu.setPosition(0,0);
                rect.setOutlineThickness(20);
                highscore = 0;
                hs_score.setPosition(Vector2f(2000, 2000));

                cout<<"Hello world!!!"<<endl;
            }
            if(rect.getPosition().y==405 && Keyboard::isKeyPressed(Keyboard::Enter))
            {
                rect.setPosition(230, 180);
                rect.setSize(Vector2f(340,110));
                menu.setPosition(2000, 2000);
                ///////mode_front.setPosition(2000, 2000);
                music_front.setPosition(0, 0);
                rect.setOutlineThickness(20);
                music_Button = 1;
            }
            if(music_Button == 1)
            {
                music_front.setPosition(0,0);
                if(rect.getPosition().y==180 && rect.getPosition().y <= 380)
                {
                    if( Keyboard::isKeyPressed(Keyboard::Down))
                        rect.setPosition(230,380);
                }

                else if(rect.getPosition().y == 380)
                    if( Keyboard::isKeyPressed(Keyboard::Up))
                        rect.setPosition(rect.getPosition().x, 180);



                if(rect.getPosition().x == 230 &&rect.getPosition().y == 180 && Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    music.setVolume(200);
                    hit.setVolume(200);
                    crash_sound = 1;
                }
                else if(rect.getPosition().x == 230 &&rect.getPosition().y == 380 && Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    music.setVolume(0);
                    hit.setVolume(0);
                    crash_sound = 0;

                }
                if(Keyboard::isKeyPressed(Keyboard::BackSpace))
                {
                    music_Button = 0;
                    music_front.setPosition(2000, 2000);
                    rect.setPosition(250, 55);
                    rect.setSize(Vector2f(300,110));
                    menu.setPosition(0,0);
                    //////////rect.setOutlineThickness(20);
                }
            }
            if(rect.getPosition().y==580 && Keyboard::isKeyPressed(Keyboard::Enter))
                return 0;

            if(event.key.code==Keyboard::Escape)
                return 0;
            start.clear();

        }
        start.clear();
        start.draw(highscore_front);
        start.draw(music_front);
        start.draw(menu);
        start.draw(rect);
        start.draw(hs_score);
        ////start.draw(shape);
        start.display();

    }
    double score = 0;
    double live=3,level=1;
a:
    srand(time(NULL));///for random number
    int speed1=0,speed2=0,speed3=0,speed4=0;
    int speed=100;
    speed1=rand()% 4+ 1;
    speed2=rand()% 4+ 1;
    speed3=rand()% 4+ 1;
    speed4=rand()% 4+ 1;

    /*sf::Clock clock;
    int countdown = 30;
     std::string countdownString;
    std::ostringstream convert;
    convert << countdown;
    countdownString = convert.str();*/


    int ecar1pos=210,ecar2pos=310,ecar3pos=440,ecar4pos=560,road1pos=0,road2pos=0;
    int ecar21pos=210,ecar22pos=310,ecar23pos=440,ecar24pos=560;
    int bframe=0;
    int coinposrand=0,carposrand=0;
    coinposrand=rand()%4+1;
    carposrand=rand()%4+1;
    int x=4,y=4;
    /*Font myfont;
    Text myscore;
    Text mylive;
    Text mylevel;
    Text myhigh;
    Text text1;
    Text text2;
    Text text3;
    Text text4;
    Text text5;
    /////// bool playButton = false;
    myfont.loadFromFile("shakil123.ttf");*/
    RenderWindow Window(VideoMode(800,800),"Shakil && Fahim");
    ///////Menu menu(Window.getSize().x, Window.getSize().y);
    if(live==0)
    {
        while(Window.isOpen())///open window for start menu
        {

            Event s;
            while(Window.pollEvent(s))
            {
                Texture go;
                go.loadFromFile("gameover.jpg");
                Sprite gameover(go);
                Window.clear();
                Window.draw(gameover);
                Window.display();
                cout<<"Score From Game : "<<score<<endl;
                ofstream write;
                write.open("high score.txt");
                if(write.is_open())
                {
                    if(score > hscore)
                    {
                        write<<score;
                    }
                }
                write.close();
                //////Sleep(500);
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    return 0;
                }
                if(Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    goto b;
                }

            }
        }

    }

    Texture q1;
    q1.loadFromFile("ghi.jpg ");
    Sprite road1(q1);
    road1.setPosition(0,0);
    Sprite road2(q1);
    road2.setPosition(0,-1500);
    /////////////

    Texture p2;
    p2.loadFromFile("car.png");
    Sprite car(p2);
    car.setPosition(365,700);

    Texture p3;
    p3.loadFromFile("ecar.png");
    Sprite ecar1(p3);
    ecar1.setPosition(210,-120);

    Texture p4;
    p4.loadFromFile("ecar.png");
    Sprite ecar2(p4);
    ecar2.setPosition(310,-120);

    Texture p5;
    p5.loadFromFile("ecar.png");
    Sprite ecar3(p5);
    ecar3.setPosition(440,-120);

    Texture p7;
    p7.loadFromFile("ecar.png");
    Sprite ecar4(p7);
    ecar4.setPosition(560,-120);


    Texture p20;
    p20.loadFromFile("ECAR3.png");
    Sprite ecar21(p20);
    ecar21.setPosition(210,-120);

    Texture p21;
    p21.loadFromFile("ECAR3.png");
    Sprite ecar22(p21);
    ecar22.setPosition(310,-120);

    Texture p22;
    p22.loadFromFile("ECAR3.png");
    Sprite ecar23(p20);
    ecar23.setPosition(440,-120);

    Texture p23;
    p23.loadFromFile("ECAR3.png");
    Sprite ecar24(p23);
    ecar24.setPosition(560,-120);
//////////////////
    Texture p8;
    p8.loadFromFile("coin.png");
    Sprite coin(p8);
    coin.setPosition(440,-120);
    Texture p9;
    p9.loadFromFile("icon2.jpg");
    Sprite icon(p9);
    icon.setPosition(600,600);

    Texture p6;
    p6.loadFromFile("boom.jpg");
    Sprite boom(p6);
    boom.setPosition(440,440);


    music.play();///to play car sound
    music.setLoop(true);///to repeat car sound
d:
    while(Window.isOpen()&&score<=3000)///to open window///game loop
    {
        ///score
        myscore.setFont(myfont);
        myscore.setString(s(score));
        myscore.setCharacterSize(14);
        myscore.setColor(Color::Red);
        myscore.setPosition(135,43);
        /// score+=0.05; ///this score will change to string
        speed+=0.05;
        ////////
        text1.setFont(myfont);
        text1.setString("CAR RACING");///write text to print it
        text1.setCharacterSize(20);///text size
        text1.setColor(Color::Cyan);///text color
        text1.setPosition(10,5);///text position

        //////
        text2.setFont(myfont);
        text2.setString("SCORE:");///write text to print it
        text2.setCharacterSize(17);///text size
        text2.setColor(Color::Cyan);///text color
        text2.setPosition(10,40);
        ///////
        mylive.setFont(myfont);
        mylive.setString(s(live));
        mylive.setCharacterSize(20);
        mylive.setColor(Color::Red);
        mylive.setPosition(100,414);
        //////////
        text3.setFont(myfont);
        text3.setString("live:");///write text to print it
        text3.setCharacterSize(25);///text size
        text3.setColor(Color::Cyan);///text color
        text3.setPosition(10,410);///text position
        ///
        text4.setFont(myfont);
        text4.setString("level:");///write text to print it
        text4.setCharacterSize(25);///text size
        text4.setColor(Color::Red);///text color
        text4.setPosition(10,380);///text position*/
        //////////////
        text5.setFont(myfont);
        text5.setString("press tab to pause.");///write text to print it
        text5.setCharacterSize(25);///text size
        text5.setColor(Color::Red);///text color
        text5.setPosition(10,750);///text position*/
        ///

        mylevel.setFont(myfont);
        mylevel.setString(s(level));///write text to print it
        mylevel.setCharacterSize(25);///text size
        mylevel.setColor(Color::Red);///text color
        mylevel.setPosition(120,382);///text position*/
        ////////////////////////game loop////////
        Window.setFramerateLimit(120);
        Event e;
        while(Window.pollEvent(e))
        {
            if(e.type==Event::Closed)
                Window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)&&car.getPosition().x>200)///left side move
        {
            car.move(-3.5,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)&&car.getPosition().x<560)///right side move
        {
            car.move(3.5,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)&&car.getPosition().y>0)///up side move
        {
            car.move(0,-3.5);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)&&car.getPosition().y<700)///down side move
        {
            car.move(0,3.5);
        }
        if(ecar1.getPosition().y>=800)
            ecar1.setPosition(ecar1pos,-120);
        if(ecar2.getPosition().y>=800)
            ecar2.setPosition(ecar2pos,-120);
        if(ecar3.getPosition().y>=800)
            ecar3.setPosition(ecar3pos,-120);

        if(ecar4.getPosition().y>=800)
            ecar4.setPosition(ecar4pos,-120);
        /////////////////////////
        /* ecar1.move(0,speed1/2+1);      ///to set position for cars
         ecar2.move(0,speed2/2+1.5);      ///to set position for cars
         ecar3.move(0,speed3/2+0.25);      ///to set position for cars
         ecar4.move(0,speed4/2+.75);*/     ///to set position for cars
        ///////////
        if(ecar1.getPosition().y>=800)
            speed1=rand()%4+1;
        if(ecar2.getPosition().y>=800)
            speed2=rand()%4+1;
        if(ecar3.getPosition().y>=800)
            speed3=rand()%4+1;
        if(ecar4.getPosition().y>=800)
            speed4=rand()%4+1;
        /////
        if(ecar1.getPosition().y>=-120)
            speed1=rand()%4+1;
        if(ecar2.getPosition().y>=-120)
            speed2=rand()%4+1;
        if(ecar3.getPosition().y>=-120)
            speed3=rand()%4+1;
        if(ecar4.getPosition().y>=-120)
            speed4=rand()%4+1;
        /////////////////////
        if(car.getGlobalBounds().intersects(ecar1.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar2.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar3.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar4.getGlobalBounds()))
        {

/////            /music.pause();
            music.pause();
            Sound hit;
            hit.setBuffer(buffer);
            hit.play();
            hit.setVolume(0);

            if(crash_sound == 1)
            {
                hit.setVolume(150);
            }
            if(car.getPosition().y>0&&car.getPosition().y<450)
            {
                for(bframe=0; bframe<580; bframe+=200)
                {
                    boom.setPosition(car.getPosition().x-100,car.getPosition().y-100);
                    /////boom.setPosition(150,150);
                    Window.draw(boom);
                    Window.display();
                    Sleep(500);
                }
                live--;
                goto a;
            }
            else
            {
                for(bframe=0; bframe<580; bframe+=200)
                {
                    boom.setPosition(car.getPosition().x-200,car.getPosition().y-300);
                    ///boom.setPosition(150,150);
                    Window.draw(boom);
                    Window.display();
                    Sleep(500);
                }
                live--;
                goto a;
            }
        }
        ////////coin/////////
        if(Keyboard::isKeyPressed(Keyboard::Escape))///down side move
        {
            goto b;
        }
        if(tab==1)
        {
            score+=0;
            road1.move(0,0);
            road2.move(0,0);
            coin.move(0,0);
        }
        if(tab==0)
        {
            ecar1.move(0,speed1/2+1);      ///to set position for cars
            ecar2.move(0,speed2/2+1.5);      ///to set position for cars
            ecar3.move(0,speed3/2+0.25);      ///to set position for cars
            ecar4.move(0,speed4/2+1.75);
            score+=.05;
            road1.move(0,2);
            road2.move(0,2);
            coin.move(0,4);
        }

        /* bool gamePause=false;
          int timer = clock.getElapsedTime().asSeconds();
          std::cout << timer << std::endl;
          if (timer > 0) {
                     countdown--;
                     convert << countdown;

                     countdownString = convert.str();
                     myscore.setString(countdownString);
                     clock.restart();
                 }
        if(Keyboard::isKeyPressed(Keyboard::Tab))
        {
        	gamePause = true;
        	while(gamePause == true)
        	{
        		std::cout << "GAME PAUSED" << std::endl;
        		//delay before able to unpause
        		if(timer > 1)
        		{
        			if(Keyboard::isKeyPressed(Keyboard::Tab))
        			{
        				gamePause = false;
        				std::cout << "GAME UNPAUSED" << std::endl;
        			}
        		}
        	}
         clock.restart();
        }
        */



        /*if(Keyboard::isKeyPressed(Keyboard::Tab))
        {
          Event.pause();

        }*/
        if(car.getGlobalBounds().intersects(coin.getGlobalBounds()))
        {
            if(coinposrand==1)
                coin.setPosition(210,-120);
            if(coinposrand==2)
                coin.setPosition(310,-120);
            if(coinposrand==3)
                coin.setPosition(440,-120);
            if(coinposrand==4)
                coin.setPosition(560,-120);
            score=score+100;
        }

        ////
        /*if(ecar1.getGlobalBounds().intersects(car.getGlobalBounds())||ecar2.getGlobalBounds().intersects(car.getGlobalBounds())||
           ecar3.getGlobalBounds().intersects(car.getGlobalBounds())||ecar4.getGlobalBounds().intersects(car.getGlobalBounds()))
        {
            if(carposrand==1)
                car.setPosition(365,700);
            if(carposrand==2)
                car.setPosition(310,-120);
            if(carposrand==3)
                car.setPosition(440,-120);
            if(carposrand==4)
                car.setPosition(560,-120);
        }*/

        ////
        if(coin.getPosition().y>=810)
        {
            if(coinposrand==1)
                coin.setPosition(210,-120);
            if(coinposrand==2)
                coin.setPosition(310,-120);
            if(coinposrand==3)
                coin.setPosition(440,-120);
            if(coinposrand==4)
                coin.setPosition(560,-120);
            coinposrand=rand()%4+1;
        }

        if(road1.getPosition().y>=1500)
        {

            road1.setPosition(0,-1500);

        }

        if(road2.getPosition().y>=1500)
        {

            road2.setPosition(0,-1500);

        }
        //
        /////// cout<<"shhh"<<endl;
        if(Keyboard::isKeyPressed(Keyboard::Tab) && tab==0)
        {
            /////cout<<"we"<<endl;
            tab=1;
            while(Window.isOpen())
            {
                Event r;
                while(Window.pollEvent(r))
                {

                    Sprite icon(p9);
                    icon.setPosition(200,200);
                    Window.draw(icon);
                    /////Window.clear();
                    Window.display();
                    //////Sleep(500);
                    if(tab== 1&& Keyboard::isKeyPressed(Keyboard::Space))
                    {
                        icon.setPosition(2000,2000);
                        ///cout<<"shakil"<<endl;
                        tab=0;
                        /// Window.isOpen();
                        break;
                    }
                    //
                    // if(Keyboard::isKeyPressed(Keyboard::Enter)){
                    //// goto b;
                    // }

                }
                if(tab==0)
                {
                    ////////cout<<"ashik"<<endl;
                    break;
                }
                ////tab--;
            }
            //Window.clear();
            Window.draw(road1);
            Window.draw(road2);
            Window.draw(coin);
            Window.draw(car);
            Window.draw(ecar1);
            Window.draw(ecar2);    ///to display photo
            Window.draw(ecar3);
            Window.draw(ecar4);
            Window.draw(myscore);
            Window.draw(mylive);
            Window.draw(mylevel);
            Window.draw(text1);
            Window.draw(text2);
            Window.draw(text3);
            Window.draw(text4);
            Window.draw(text5);
            Window.display();

        }

        //
        // road1.move(0,2);
        // road2.move(0,2);
        //coin.move(0,4);
        //roadposrand=rand()%4+1;
        coinposrand=rand()%4+1;
        Window.clear();
        Window.draw(road1);
        Window.draw(road2);
        Window.draw(coin);
        Window.draw(car);
        Window.draw(ecar1);
        Window.draw(ecar2);    ///to display photo
        Window.draw(ecar3);
        Window.draw(ecar4);
        Window.draw(myscore);
        Window.draw(mylive);
        Window.draw(mylevel);
        Window.draw(text1);
        Window.draw(text2);
        Window.draw(text3);
        Window.draw(text4);
        Window.draw(text5);
        Window.display();
    }
    while(Window.isOpen() && score<5000)///to open window///game loop
    {
        ////live=live+1;
        level=2;
        myscore.setFont(myfont);
        myscore.setString(s(score));
        myscore.setCharacterSize(14);
        myscore.setColor(Color::Red);
        myscore.setPosition(135,43);
        score+=0.05; ///this score will change to string
        speed+=0.05;
        ////////
        text1.setFont(myfont);
        text1.setString("CAR RACING");///write text to print it
        text1.setCharacterSize(20);///text size
        text1.setColor(Color::Cyan);///text color
        text1.setPosition(10,5);///text position

        //////
        text2.setFont(myfont);
        text2.setString("SCORE:");///write text to print it
        text2.setCharacterSize(17);///text size
        text2.setColor(Color::Cyan);///text color
        text2.setPosition(10,40);
        ///////
        mylive.setFont(myfont);
        mylive.setString(s(live));
        mylive.setCharacterSize(20);
        mylive.setColor(Color::Red);
        mylive.setPosition(100,414);
        //////////
        text3.setFont(myfont);
        text3.setString("live:");///write text to print it
        text3.setCharacterSize(25);///text size
        text3.setColor(Color::Cyan);///text color
        text3.setPosition(10,410);///text position
        ///////////////
        mylevel.setFont(myfont);
        mylevel.setString(s(level));///write text to print it
        mylevel.setCharacterSize(25);///text size
        mylevel.setColor(Color::Red);///text color
        mylevel.setPosition(120,382);///text position*/
        //////////
        text4.setFont(myfont);
        text4.setString("level:");///write text to print it
        text4.setCharacterSize(25);///text size
        text4.setColor(Color::Red);///text color
        text4.setPosition(10,380);///text position
        ///////
        text5.setFont(myfont);
        text5.setString("press tab to pause.");///write text to print it
        text5.setCharacterSize(25);///text size
        text5.setColor(Color::Red);///text color
        text5.setPosition(10,750);///text position*/
        ///
        ////////////////////////game loop////////
        Window.setFramerateLimit(140);
        Event e;
        while(Window.pollEvent(e))
        {
            if(e.type==Event::Closed)
                Window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)&&car.getPosition().x>200)///left side move
        {
            car.move(-3.5,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)&&car.getPosition().x<560)///right side move
        {
            car.move(3.5,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)&&car.getPosition().y>0)///up side move
        {
            car.move(0,-3.5);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)&&car.getPosition().y<700)///down side move
        {
            car.move(0,3.5);
        }
        if(ecar21.getPosition().y>=800)
            ecar21.setPosition(ecar21pos,-120);
        if(ecar22.getPosition().y>=800)
            ecar22.setPosition(ecar22pos,-120);
        if(ecar23.getPosition().y>=800)
            ecar23.setPosition(ecar23pos,-120);
        if(ecar24.getPosition().y>=800)
            ecar24.setPosition(ecar24pos,-120);
        /////////////////////////
        ecar21.move(0,speed1/2+1);      ///to set position for cars
        ecar22.move(0,speed2/2+1.5);      ///to set position for cars
        ecar23.move(0,speed3/2+0.25);      ///to set position for cars
        ecar24.move(0,speed4/2+.75);      ///to set position for cars
        ///////////

        if(ecar21.getPosition().y>=800)
            speed1=rand()%4+1;
        if(ecar22.getPosition().y>=800)
            speed2=rand()%4+1;
        if(ecar23.getPosition().y>=800)
            speed3=rand()%4+1;
        if(ecar24.getPosition().y>=800)
            speed4=rand()%4+1;
        /////
        if(ecar21.getPosition().y>=-120)
            speed1=rand()%4+1;
        if(ecar22.getPosition().y>=-120)
            speed2=rand()%4+1;
        if(ecar23.getPosition().y>=-120)
            speed3=rand()%4+1;
        if(ecar24.getPosition().y>=-120)
            speed4=rand()%4+1;
        /////////////////////
        if(car.getGlobalBounds().intersects(ecar21.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar22.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar23.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar24.getGlobalBounds()))
        {
            music.pause();
            Sound hit;
            hit.setBuffer(buffer);
            hit.play();
            hit.setVolume(0);

            if(crash_sound == 1)
            {
                hit.setVolume(150);
            }
            if(car.getPosition().y>0&&car.getPosition().y<450)
            {
                for(bframe=0; bframe<580; bframe+=200)
                {
                    boom.setPosition(car.getPosition().x-100,car.getPosition().y-100);
                    /////boom.setPosition(150,150);
                    Window.draw(boom);
                    Window.display();
                    Sleep(500);
                }
                live--;
                goto a;
            }
            else
            {
                for(bframe=0; bframe<580; bframe+=200)
                {
                    boom.setPosition(car.getPosition().x-200,car.getPosition().y-300);
                    ///boom.setPosition(150,150);
                    Window.draw(boom);
                    Window.display();
                    Sleep(500);
                }
                live--;
                goto a;
            }

        }
        ///////////////
        if(Keyboard::isKeyPressed(Keyboard::Escape))///down side move
        {
            goto b;
        }
        /* bool gamePause=false;
          int timer = clock.getElapsedTime().asSeconds();
          std::cout << timer << std::endl;
          if (timer > 0) {
                     countdown--;
                     convert << countdown;
                     countdownString = convert.str();
                     myscore.setString(countdownString);
                     clock.restart();
                 }
        if(Keyboard::isKeyPressed(Keyboard::Tab))
        {
        	gamePause = true;
        	while(gamePause == true)
        	{
        		std::cout << "GAME PAUSED" << std::endl;
        		//delay before able to unpause
        		if(timer > 1)
        		{
        			if(Keyboard::isKeyPressed(Keyboard::Tab))
        			{
        				gamePause = false;
        				std::cout << "GAME UNPAUSED" << std::endl;
        			}
        		}
        	}
         clock.restart();
        }
        */
        if(tab==1)
        {
            score+=0;
            road1.move(0,0);
            road2.move(0,0);
            coin.move(0,0);
        }
        if(tab==0)
        {
            ecar1.move(0,speed1/2+1.7);      ///to set position for cars
            ecar2.move(0,speed2/2+2.2);      ///to set position for cars
            ecar3.move(0,speed3/2+1.75);      ///to set position for cars
            ecar4.move(0,speed4/2+1.0);
            score+=.10;
            speed+=.02;
            road1.move(0,2.5);
            road2.move(0,2.5);
            coin.move(0,6);
        }
///////////

        if(car.getGlobalBounds().intersects(coin.getGlobalBounds()))
        {
            if(coinposrand==1)
                coin.setPosition(210,-120);
            if(coinposrand==2)
                coin.setPosition(310,-120);
            if(coinposrand==3)
                coin.setPosition(440,-120);
            if(coinposrand==4)
                coin.setPosition(560,-120);
            score=score+100;
        }
        if(coin.getPosition().y>=810)
        {
            if(coinposrand==1)
                coin.setPosition(210,-120);
            if(coinposrand==2)
                coin.setPosition(310,-120);
            if(coinposrand==3)
                coin.setPosition(440,-120);
            if(coinposrand==4)
                coin.setPosition(560,-120);
            coinposrand=rand()%4+1;
        }


        if(road1.getPosition().y>=1500)
        {
            road1.setPosition(0,-1500);

        }

        if(road2.getPosition().y>=1500)
        {
            road2.setPosition(0,-1500);

        }

        if(Keyboard::isKeyPressed(Keyboard::Tab) && tab==0)
        {
            cout<<"we"<<endl;
            tab=1;
            while(Window.isOpen())
            {
                Event r;
                while(Window.pollEvent(r))
                {

                    Sprite icon(p9);
                    icon.setPosition(200,200);
                    Window.draw(icon);
                    /////Window.clear();
                    Window.display();
                    //////Sleep(500);
                    if(tab== 1&& Keyboard::isKeyPressed(Keyboard::Space))
                    {
                        icon.setPosition(2000,2000);
                        cout<<"shakil"<<endl;
                        tab=0;
                        /// Window.isOpen();
                        break;
                    }
                    //
                    // if(Keyboard::isKeyPressed(Keyboard::Enter)){
                    //// goto b;
                    // }

                }
                if(tab==0)
                {
                    cout<<"ashik"<<endl;
                    break;
                }
                ////tab--;
            }
            //Window.clear();
            Window.draw(road1);
            Window.draw(road2);
            Window.draw(coin);
            Window.draw(icon);
            Window.draw(car);
            Window.draw(ecar1);
            Window.draw(ecar2);    ///to display photo
            Window.draw(ecar3);
            Window.draw(ecar4);
            Window.draw(myscore);
            Window.draw(mylive);
            Window.draw(mylevel);
            Window.draw(text1);
            Window.draw(text2);
            Window.draw(text3);
            Window.draw(text4);
            Window.draw(text5);
            Window.display();

        }

        //////////////


        /*road1.move(0,4);
        road2.move(0,4);
        coin.move(0,6);
        //roadposrand=rand()%4+1;*/
        coinposrand=rand()%4+1;
        Window.clear();
        Window.draw(road1);
        Window.draw(road2);
        ///Window.clear();
        Window.draw(coin);
        ////////Window.draw(icon);
        Window.draw(car);
        Window.draw(ecar21);
        Window.draw(ecar22);
        Window.draw(ecar23);
        Window.draw(ecar24);
        Window.draw(myscore);
        Window.draw(mylive);
        Window.draw(mylevel);
        Window.draw(text1);
        Window.draw(text2);
        Window.draw(text3);
        Window.draw(text4);
        Window.draw(text5);
        ////window.draw(text4);
        Window.display();
    }


    /////////////////
    while(Window.isOpen())///to open window///game loop
    {
        level=3;
        myscore.setFont(myfont);
        myscore.setString(s(score));
        myscore.setCharacterSize(14);
        myscore.setColor(Color::Red);
        myscore.setPosition(135,43);
        ////////
        text1.setFont(myfont);
        text1.setString("CAR RACING");///write text to print it
        text1.setCharacterSize(20);///text size
        text1.setColor(Color::Cyan);///text color
        text1.setPosition(10,5);///text position

        //////
        text2.setFont(myfont);
        text2.setString("SCORE:");///write text to print it
        text2.setCharacterSize(17);///text size
        text2.setColor(Color::Cyan);///text color
        text2.setPosition(10,40);
        ///////
        mylive.setFont(myfont);
        mylive.setString(s(live));
        mylive.setCharacterSize(20);
        mylive.setColor(Color::Red);
        mylive.setPosition(100,414);
        //////////
        text3.setFont(myfont);
        text3.setString("live:");///write text to print it
        text3.setCharacterSize(25);///text size
        text3.setColor(Color::Cyan);///text color
        text3.setPosition(10,410);///text position
        ///////////////
        mylevel.setFont(myfont);
        mylevel.setString(s(level));///write text to print it
        mylevel.setCharacterSize(25);///text size
        mylevel.setColor(Color::Red);///text color
        mylevel.setPosition(120,382);///text position*/
        //////////
        text4.setFont(myfont);
        text4.setString("level:");///write text to print it
        text4.setCharacterSize(25);///text size
        text4.setColor(Color::Red);///text color
        text4.setPosition(10,380);///text position
        //////
        text5.setFont(myfont);
        text5.setString("press tab to pause.");///write text to print it
        text5.setCharacterSize(25);///text size
        text5.setColor(Color::Red);///text color
        text5.setPosition(10,750);///text position*/
        ///
        ////////////////////////game loop////////
        Window.setFramerateLimit(130);
        Event e;
        while(Window.pollEvent(e))
        {
            if(e.type==Event::Closed)
                Window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)&&car.getPosition().x>200)///left side move
        {
            car.move(-4.5,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)&&car.getPosition().x<560)///right side move
        {
            car.move(4.5,0);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)&&car.getPosition().y>0)///up side move
        {
            car.move(0,-4.5);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)&&car.getPosition().y<700)///down side move
        {
            car.move(0,4.5);
        }
        if(ecar21.getPosition().y>=800)
            ecar21.setPosition(ecar21pos,-120);
        if(ecar22.getPosition().y>=800)
            ecar22.setPosition(ecar22pos,-120);
        if(ecar23.getPosition().y>=800)
            ecar23.setPosition(ecar23pos,-120);
        if(ecar24.getPosition().y>=800)
            ecar24.setPosition(ecar24pos,-120);
        /////////////////////////
        /* ecar21.move(0,speed1/2+1);      ///to set position for cars
         ecar22.move(0,speed2/2+1.5);      ///to set position for cars
         ecar23.move(0,speed3/2+0.25);      ///to set position for cars
         ecar24.move(0,speed4/2+.75); */     ///to set position for cars
        ///////////

        if(ecar21.getPosition().y>=800)
            speed1=rand()%4+1;
        if(ecar22.getPosition().y>=800)
            speed2=rand()%4+1;
        if(ecar23.getPosition().y>=800)
            speed3=rand()%4+1;
        if(ecar24.getPosition().y>=800)
            speed4=rand()%4+1;
        /////
        if(ecar21.getPosition().y>=-120)
            speed1=rand()%4+1;
        if(ecar22.getPosition().y>=-120)
            speed2=rand()%4+1;
        if(ecar23.getPosition().y>=-120)
            speed3=rand()%4+1;
        if(ecar24.getPosition().y>=-120)
            speed4=rand()%4+1;
        /////////////////////
        if(car.getGlobalBounds().intersects(ecar21.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar22.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar23.getGlobalBounds())||
                car.getGlobalBounds().intersects(ecar24.getGlobalBounds()))
        {
            music.pause();
            Sound hit;
            hit.setBuffer(buffer);
            hit.play();
            hit.setVolume(0);

            if(crash_sound == 1)
            {
                hit.setVolume(150);
            }
            if(car.getPosition().y>0&&car.getPosition().y<450)
            {
                for(bframe=0; bframe<580; bframe+=200)
                {
                    boom.setPosition(car.getPosition().x-100,car.getPosition().y-100);
                    /////boom.setPosition(150,150);
                    Window.draw(boom);
                    Window.display();
                    Sleep(500);
                }
                live--;
                goto a;
            }
            else
            {
                for(bframe=0; bframe<580; bframe+=200)
                {
                    boom.setPosition(car.getPosition().x-200,car.getPosition().y-300);
                    ///boom.setPosition(150,150);
                    Window.draw(boom);
                    Window.display();
                    Sleep(500);
                }
                live--;
                goto a;
            }

        }
        ///////////////
        if(Keyboard::isKeyPressed(Keyboard::Escape))///down side move
        {
            goto b;
        }
        /* bool gamePause=false;
          int timer = clock.getElapsedTime().asSeconds();
          std::cout << timer << std::endl;
          if (timer > 0) {
                     countdown--;
                     convert << countdown;
                     countdownString = convert.str();
                     myscore.setString(countdownString);
                     clock.restart();
                 }
        if(Keyboard::isKeyPressed(Keyboard::Tab))
        {
        	gamePause = true;
        	while(gamePause == true)
        	{
        		std::cout << "GAME PAUSED" << std::endl;
        		//delay before able to unpause
        		if(timer > 1)
        		{
        			if(Keyboard::isKeyPressed(Keyboard::Tab))
        			{
        				gamePause = false;
        				std::cout << "GAME UNPAUSED" << std::endl;
        			}
        		}
        	}
         clock.restart();
        }
        */
        if(tab==1)
        {
            score+=0;
            road1.move(0,0);
            road2.move(0,0);
            coin.move(0,0);
        }
        if(tab==0)
        {
            ecar21.move(0,speed1/2+3.9);      ///to set position for cars
            ecar22.move(0,speed2/2+2.0);      ///to set position for cars
            ecar23.move(0,speed3/2+3.0);      ///to set position for cars
            ecar24.move(0,speed4/2+2.5);
            score+=.20;
            speed+=0.04;
            road1.move(0,2);
            road2.move(0,2);
            coin.move(0,8);
        }
///////////

        if(car.getGlobalBounds().intersects(coin.getGlobalBounds()))
        {
            if(coinposrand==1)
                coin.setPosition(210,-120);
            if(coinposrand==2)
                coin.setPosition(310,-120);
            if(coinposrand==3)
                coin.setPosition(440,-120);
            if(coinposrand==4)
                coin.setPosition(560,-120);
            score=score+100;
        }
        if(coin.getPosition().y>=810)
        {
            if(coinposrand==1)
                coin.setPosition(210,-120);
            if(coinposrand==2)
                coin.setPosition(310,-120);
            if(coinposrand==3)
                coin.setPosition(440,-120);
            if(coinposrand==4)
                coin.setPosition(560,-120);
            coinposrand=rand()%4+1;
        }


        if(road1.getPosition().y>=1500)
        {
            road1.setPosition(0,-1500);

        }

        if(road2.getPosition().y>=1500)
        {
            road2.setPosition(0,-1500);

        }

        if(Keyboard::isKeyPressed(Keyboard::Tab) && tab==0)
        {
            cout<<"we"<<endl;
            tab=1;
            while(Window.isOpen())
            {
                Event r;
                while(Window.pollEvent(r))
                {

                    Sprite icon(p9);
                    icon.setPosition(200,200);
                    Window.draw(icon);
                    /////Window.clear();
                    Window.display();
                    //////Sleep(500);
                    if(tab== 1&& Keyboard::isKeyPressed(Keyboard::Space))
                    {
                        icon.setPosition(2000,2000);
                        cout<<"shakil"<<endl;
                        tab=0;
                        /// Window.isOpen();
                        break;
                    }
                    //
                    // if(Keyboard::isKeyPressed(Keyboard::Enter)){
                    //// goto b;
                    // }

                }
                if(tab==0)
                {
                    cout<<"ashik"<<endl;
                    break;
                }
                ////tab--;
            }
            //Window.clear();
            Window.draw(road1);
            Window.draw(road2);
            Window.draw(coin);
            Window.draw(icon);
            Window.draw(car);
            Window.draw(ecar1);
            Window.draw(ecar2);    ///to display photo
            Window.draw(ecar3);
            Window.draw(ecar4);
            Window.draw(myscore);
            Window.draw(mylive);
            Window.draw(mylevel);
            Window.draw(text1);
            Window.draw(text2);
            Window.draw(text3);
            Window.draw(text4);
            Window.draw(text5);
            Window.display();

        }

        //////////////


        /*road1.move(0,4);
        road2.move(0,4);
        coin.move(0,6);
        //roadposrand=rand()%4+1;*/
        coinposrand=rand()%4+1;
        Window.clear();
        Window.draw(road1);
        Window.draw(road2);
        ///Window.clear();
        Window.draw(coin);
        ////////Window.draw(icon);
        Window.draw(car);
        Window.draw(ecar21);
        Window.draw(ecar22);
        Window.draw(ecar23);
        Window.draw(ecar24);
        Window.draw(myscore);
        Window.draw(mylive);
        Window.draw(mylevel);
        Window.draw(text1);
        Window.draw(text2);
        Window.draw(text3);
        Window.draw(text4);
        Window.draw(text5);
        ////window.draw(text4);
        Window.display();
    }
    ///
    return 0;
}
string s(double n) ///this function to change number to string and use it for score
{
    stringstream ss;
    ss<<n;
    return ss.str();
}

