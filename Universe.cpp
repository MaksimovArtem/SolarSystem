#include "Universe.h"

void Universe::add_planet_to_the_buffer(Planet& some_planet, Uint32 color, Screen& scr)
{
  for(int i = 0; i < scr.SCREEN_WIDTH * scr.SCREEN_HEIGHT; i++)
  {
    float tmp_y = i / scr.SCREEN_WIDTH;
    float tmp_x = i % scr.SCREEN_WIDTH;
    if(sqrt((tmp_x - some_planet.x_coord) * (tmp_x - some_planet.x_coord) +
            (tmp_y - some_planet.y_coord) * (tmp_y - some_planet.y_coord)) <= some_planet.planet_radius)
      scr.buffer[i] = color;
  }
  add_orbit_to_the_buffer(some_planet, scr);

}

void Universe::add_orbit_to_the_buffer(Planet& some_planet, Screen& scr)
{
  int c = static_cast<int> (sqrt(some_planet.a * some_planet.a -
                                 some_planet.b * some_planet.b));

  std::cout << "C= " << c << std::endl;
  if(static_cast<float>((c / some_planet.a)) >= 1.0)
    std::cout << "Wrong \"Semimajor axis's\" (a) and \"Semiminor axis's \" (b) parametres" <<std::endl;
  else
  {
    int orbit_center_x = SUN_X_COORDINATE - c;
    int orbit_center_y = SUN_Y_COORDINATE;
    std::cout << "center orb_x= " << orbit_center_x << std::endl;
    std::cout << "center orb_y= " << orbit_center_y << std::endl;

    for(int i = 0; i < scr.SCREEN_WIDTH * scr.SCREEN_HEIGHT; i++)
    {
      int tmp_y = (i / scr.SCREEN_WIDTH) - orbit_center_y;
      int tmp_x = (i % scr.SCREEN_WIDTH) - orbit_center_x;
      if((((tmp_x * tmp_x) / (some_planet.a * some_planet.a))) +
          ((tmp_y * tmp_y) / (some_planet.b * some_planet.b)) - 1.0 <= 0.000000001)

      //if((static_cast<int>(((tmp_x * tmp_x) / static_cast<int>((some_planet.a * some_planet.a))))) +
      //    static_cast<int>(((tmp_y * tmp_y) / static_cast<int>((some_planet.b * some_planet.b)))) == 1)

        scr.buffer[i] = 0xFF0000FF;
    }
    std::cout<<"No Orbit proveriai"<<std::endl;
  }
}
