// Class automatically generated by Dev-C++ New Class wizard

#include "hero.h" // class's header file
#include "conio.h" //For getch;

//Child class of Character

// class constructor
Hero::Hero()
{ 
  hero_row = 1;
  hero_column = 1;
  item_count = 0;
  
  set_name ("Hero");
  set_health (10000);
  set_damage (120);
  set_defence (15);
  
  
	// insert your code here
}

// class destructor
Hero::~Hero()
{
	// insert your code here
}

//FUNCTION DEFINITIONS --------------------------------------------------------------------------

int Hero::get_hero_row()
{ return hero_row;
}
   //-----------------------------------------------------------------------------------------------
int Hero::get_hero_column()
{ return hero_column;
}
   //-----------------------------------------------------------------------------------------------
void Hero::set_hero_row(int new_row)
{ hero_row = new_row;
}
   //-----------------------------------------------------------------------------------------------
void Hero::set_hero_column(int new_column)
{ hero_column = new_column;
}

//-----------------------------------------------------------------------------------------------

 int Hero::get_item_count()
 { return item_count;
 }
 
//-----------------------------------------------------------------------------------------------

 void Hero::set_item_count(int _item_count)
 { item_count = _item_count;
 }
 
 
//-----------------------------------------------------------------------------------------------

void Hero::move()
{ 

char user_movement;
 user_movement = getch();
 
 if (user_movement == 'w')
 {  
   check_wall_w();
   check_monsters_w();
 
 }

 else if (user_movement == 'a')
 {
   check_wall_a();
   check_door_a();
   check_monsters_a();
   check_health_a();
   
 }
 
 else if (user_movement == 's')
 { check_weapon_s();
   check_wall_s();
   check_key_s();
   check_door_s();
   check_finish_s();
   check_monsters_s();
 }
 
 
 else if (user_movement == 'd')
 {
   check_wall_d();
   check_monsters_d();
   check_health_d();
 }
 else{
 	system("cls");
 	themaze -> display_maze();
 }
   
}

//-----------------------------------------------------------------------------------------------

void Hero::char_position_w()
{ themaze ->mazeboard[get_hero_row() -1][get_hero_column()] = 233;
  themaze ->mazeboard[get_hero_row()][get_hero_column()] = 255;
  set_hero_row(get_hero_row() -1);
}


//-----------------------------------------------------------------------------------------------

void Hero::char_position_a()
{ themaze ->mazeboard[get_hero_row()][get_hero_column() -1] = 233;
  themaze ->mazeboard[get_hero_row()][get_hero_column()] = 255;
  set_hero_column(get_hero_column() -1);
}


//-----------------------------------------------------------------------------------------------
 
void Hero::char_position_s()
{ themaze ->mazeboard[get_hero_row() + 1][get_hero_column()] = 233;
  themaze ->mazeboard[get_hero_row()][get_hero_column()] = 255;
  set_hero_row(get_hero_row() +1);
}
 
//-----------------------------------------------------------------------------------------------
 
void Hero::char_position_d()
{ themaze ->mazeboard[get_hero_row()][get_hero_column() +1] = 233;
  themaze ->mazeboard[get_hero_row()][get_hero_column()] = 255;
  set_hero_column(get_hero_column() +1);
}







//-------AUTO SOLVER-----------------------------------------------------------------------------

void Hero::char_position2_w()
{ themaze ->mazeboard2[get_hero_row() -1][get_hero_column()] = 233;
  themaze ->mazeboard2[get_hero_row()][get_hero_column()] = 255;
  set_hero_row(get_hero_row() -1);
}


//-----------------------------------------------------------------------------------------------

void Hero::char_position2_a()
{ themaze ->mazeboard2[get_hero_row()][get_hero_column() -1] = 233;
  themaze ->mazeboard2[get_hero_row()][get_hero_column()] = 255;
  set_hero_column(get_hero_column() -1);
}


//-----------------------------------------------------------------------------------------------
 
void Hero::char_position2_s()
{ themaze ->mazeboard2[get_hero_row() + 1][get_hero_column()] = 233;
  themaze ->mazeboard2[get_hero_row()][get_hero_column()] = 255;
  set_hero_row(get_hero_row() +1);
}
 
//-----------------------------------------------------------------------------------------------
 
void Hero::char_position2_d()
{ themaze ->mazeboard2[get_hero_row()][get_hero_column() +1] = 233;
  themaze ->mazeboard2[get_hero_row()][get_hero_column()] = 255;
  set_hero_column(get_hero_column() +1);
}


//-----------------------------------------------------------------------------------------------

 
void Hero::check_wall_w()
{    
     system("cls");
     
     if (themaze -> isWall(get_hero_row() -1, get_hero_column() ) == true)
    {
     char_position_w();
    }

    
    themaze ->display_maze();
}

//-----------------------------------------------------------------------------------------------


void Hero::check_wall_a()
{  system("cls");

   if (themaze -> isWall(get_hero_row(), get_hero_column() -1 ) == true)
   { 
    char_position_a();
   }
   
   themaze -> display_maze();
}


//-----------------------------------------------------------------------------------------------


void Hero::check_wall_s()
{  
   system("cls");

   if (themaze -> isWall(get_hero_row() + 1, get_hero_column() ) == true)
   { 
    char_position_s();
 
   }
   
   themaze -> display_maze();
}

//-----------------------------------------------------------------------------------------------



void Hero::check_wall_d()
{  system("cls");

   if (themaze -> isWall(get_hero_row(), get_hero_column() + 1 ) == true)
   {  char_position_d(); 
 
   }
    themaze -> display_maze(); 
}

//-----------------------------------------------------------------------------------------------
 
        
void Hero::check_door_a()
{   
   if (themaze -> isDoor(get_hero_row(), get_hero_column() -1 ) == true)
   { 
     system("cls");
     
       if (themaze -> mazeboard[9][10] == char (255))
       {
        char_position_a();
        themaze -> display_maze();
        set_item_count(get_item_count() - 1);
        cout<<"You have opened the door"<<endl;
       }
       else
       {
        themaze -> display_maze();
        cout<<"You must find the Key to open the maze"<<endl;
       }
   }
}


//-----------------------------------------------------------------------------------------------


void Hero::check_door_s()
{    
   if (themaze ->isDoor(get_hero_row() + 1, get_hero_column() ) == true)
   { 
      system("cls");
      
       if (themaze -> mazeboard[9][10] == char (255))
       {
        char_position_s();
        themaze -> display_maze();
        set_item_count(get_item_count() - 1);
        cout<<"You have opened the door"<<endl;
       }
       else
       {
        themaze -> display_maze();
        cout<<"You must find the Key to open the maze"<<endl;
       }
   }
}


//-----------------------------------------------------------------------------------------------
      
        
void Hero::check_key_s()
{    
     if (themaze -> isKey(get_hero_row() + 1, get_hero_column() ) == true)
   {  system("cls");
       char_position_s();
       set_item_count(get_item_count() + 1);
       themaze -> display_maze();
       cout<<"You have the key!"<<endl;
   }
   
}

//-----------------------------------------------------------------------------------------------
        
void Hero::check_finish_s()
{
     if (themaze -> isFinishLine(get_hero_row() + 1, get_hero_column() ) == true)
   {   system("cls");
       char_position_s();
       themaze -> display_maze();
       cout<<"You have survived and won the game!!!"<<endl;
   }
}


void Hero::check_monsters_w()
{    if ( themaze -> isMonster(get_hero_row() -1 , get_hero_column())  == true)
     {    fight();
     }
}

//-----------------------------------------------------------------------------------------------

void Hero::check_monsters_a()
{    if ( themaze -> isMonster(get_hero_row() , get_hero_column() -1 ) == true)
     {    fight();
     }
}

//-----------------------------------------------------------------------------------------------

void Hero::check_monsters_s()
{    if (themaze -> isMonster(get_hero_row() + 1, get_hero_column() ) == true)
     {    fight();
     }
}

//-----------------------------------------------------------------------------------------------

void Hero::check_monsters_d()
{    if ( themaze -> isMonster(get_hero_row() , get_hero_column() +1 ) == true)
     {    fight();
     }
}

//-----------------------------------------------------------------------------------------------


void Hero::fight()
{    //MONSTER 1
     if (get_hero_row() == 1 && get_hero_column() == 4)
     {
        
        exchange_health(themonster1);
        
        if (themonster1 -> get_health() <= 0)
        {system("cls");
        char_position_a();
        themaze -> display_maze();
        cout<<"You destroyed "<<themonster1 -> get_name()<<"!"<<endl;
        }
     }
     
     //MONSTER 2
     else if ((get_hero_row() == 3 && get_hero_column() == 4) || (get_hero_row() == 5 && get_hero_column() == 4))
     {
     
        exchange_health(themonster2);
        
        if ( (themonster2 -> get_health() <= 0) && (get_hero_row() == 3 && get_hero_column() == 4))
        {system("cls");
        char_position_s();
        themaze -> display_maze();
        cout<<"You destroyed "<<themonster2 -> get_name()<<"!"<<endl;
        }
        
        else if ( (themonster2 -> get_health() <= 0) && (get_hero_row() == 5 && get_hero_column() == 4)) //These are due to the possible different positons hero can be to fight the monsters
        { system("cls");
          char_position_w();
          themaze -> display_maze();
          cout<<"You destroyed "<<themonster2 -> get_name()<<"!"<<endl;
        }
        
     }
     
     //MONSTER 3
     else if (get_hero_row() == 3 && get_hero_column() == 9 )
     {
     	exchange_health(themonster3);
     	if ( (themonster3 -> get_health() <= 0) && (get_hero_row() == 3 && get_hero_column() == 9))
        {system("cls");
        char_position_d();
        themaze -> display_maze();
        cout<<"You destroyed "<<themonster3 -> get_name()<<"!"<<endl;
        }
     }
     
     //MONSTER 4
      else if (get_hero_row() == 6 && get_hero_column() == 9)
     { exchange_health(themonster4);
     
     	if ( (themonster4 -> get_health() <= 0) && (get_hero_row() == 6 && get_hero_column() == 9))
        {system("cls");
        char_position_s();
        themaze -> display_maze();
        cout<<"You destroyed "<<themonster4 -> get_name()<<"!"<<endl;
        }
     }
     
     //MONSTER 5
     else if ((get_hero_row() == 8 && get_hero_column() == 9) || (get_hero_row() == 7 && get_hero_column() == 10))
     { exchange_health(themonster5);
     	
     	if ( (themonster5 -> get_health() <= 0) && (get_hero_row() == 8 && get_hero_column() == 9))
        {system("cls");
        char_position_d();
        themaze -> display_maze();
        cout<<"You destroyed "<<themonster5 -> get_name()<<"!"<<endl;
        }
        
        else if ( (themonster5 -> get_health() <= 0) && (get_hero_row() == 7 && get_hero_column() == 10))
        {system("cls");
        char_position_s();
        themaze -> display_maze();
        cout<<"You destroyed "<<themonster5 -> get_name()<<"!"<<endl;
        }
     }
     
     //MONSTER 6
     else if (get_hero_row() == 9 && get_hero_column() == 3)
     { exchange_health(themonster6);
     
     	if ( (themonster6 -> get_health() <= 0) && (get_hero_row() == 9 && get_hero_column() == 3))
        {system("cls");
        char_position_d();
        themaze -> display_maze();
        cout<<"You destroyed "<<themonster6 -> get_name()<<"!"<<endl;
        }
     }
     
     //BOSS
     else if ((get_hero_row() == 10 && get_hero_column() == 5) || (get_hero_row() == 9 && get_hero_column() == 6))
     { exchange_health(theboss);
     
     	if ( (theboss -> get_health() <= 0) && (get_hero_row() == 10 && get_hero_column() == 5))
        {system("cls");
        char_position_d();
        themaze -> display_maze();
        cout<<"You destroyed "<<theboss -> get_name()<<"!"<<endl;
        }
        
        else if ( (theboss -> get_health() <= 0) && (get_hero_row() == 9 && get_hero_column() == 6))
        {system("cls");
        char_position_s();
        themaze -> display_maze();
        cout<<"You destroyed "<<theboss -> get_name()<<"!"<<endl;
        }
     }
}


void Hero::exchange_health(Monster *monsternum)
{  Monster *temp;
     temp = monsternum;
     temp -> set_health( temp -> get_health() - ( get_damage() - temp -> get_defence() ) );
     set_health ( get_health() - (temp -> get_damage() - get_defence() ) );
}


void Hero::check_health_a()
{ 
	system("cls");

   if (themaze -> isHealth(get_hero_row(), get_hero_column() -1 ) == true)
   { 
    char_position_a();
    set_health(get_health() +  1000);
    set_item_count(get_item_count() + 1);
   }
   
   themaze -> display_maze();

}
void Hero::check_health_d()
{
	system("cls");

   if (themaze -> isHealth(get_hero_row(), get_hero_column() + 1 ) == true)
   {  char_position_d(); 
 	  set_health(get_health() +  1000);
 	  set_item_count(get_item_count() + 1);
   }
    themaze -> display_maze(); 
}


void Hero::check_weapon_s()
{    
  if (themaze -> isWeapon(get_hero_row() + 1, get_hero_column() ) == true)
   { system("cls");
      char_position_s();
      set_item_count(get_item_count() + 1);
      set_damage(get_damage() + 70);
      themaze -> display_maze();
   }
       
}


        
        
