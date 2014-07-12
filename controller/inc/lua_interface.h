#ifndef INC_LUA_INTERFACE_H_
#define INC_LUA_INTERFACE_H_

#include <lua.h>
#include <lualib.h>



#define TEST_STATIC_LUA \
  /*"while get_digital(0)==0 then"\
  "end"\
  "a=1"*/\
  "while 1 do\n"\
  "   set_led(get_digital(0))"\
  /*"   a = a+1"*/\
  /*"   set_led((get_digital(0)%2)*2+(get_digital(1)%2)*4)\n"*/\
  /*"   set_digital(0,get_digital(1)*2)\n"*/\
  "   set_motor(1,get_digital(0)<10 and 0 or 100)\n"\
  "end"  /* NOLINT(*) */



void lua_register_all(lua_State *L);

int lua_set_led(lua_State *L);
int lua_get_button(lua_State *L);

int lua_get_digital(lua_State *L);
int lua_set_digital(lua_State *L);

int lua_set_motor(lua_State *L);



#endif  // INC_LUA_INTERFACE_H_

