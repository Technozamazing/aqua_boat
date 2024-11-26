Conditions for Boat Operations:

A. NO OBSTACLES

   a. When NO OBSTACLES
   {
    move FRONT;
   }


====================================================

B. ONE SIDED OBSTACLE:

    a. When ONE FRONT OBSTACLE
    {
        either move LEFT or RIGHT;
    }

    b. When ONE LEFT OBSTACLE
    {
        either move FRONT or RIGHT;
    } 

    c. When ONE RIGHT OBSTACLE
    {
        either move FRONT or LEFT
    }


====================================================

C. TWO SIDED OBSTACLES:
FRONT AND LEF
    a. When TWO,  T OBSTACLES
    {
        move RIGHT;
    }

    b. When TWO,  FRONT AND RIGHT OBSTACLES
    {
        move LEFT;
    }

    ------------------------------------------

    c. When TWO,  LEFT AND RIGHT OBSTACLES
    {
        move FRONT;
    }


====================================================

D. All THREE SIDED OBSTACLES:

    a. When THREE,  FRONT, LEFT AND RIGHT OBSTACLES
    {
        STOPBOAT;
    }
