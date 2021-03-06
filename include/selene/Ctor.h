#pragma once

#include "BaseFun.h"

namespace sel {

template <typename T, typename... Args>
class Ctor : public BaseFun {
private:
    using _ctor_type = std::function<void(lua_State *, detail::decay_primitive<Args>...)>;
    _ctor_type _ctor;

public:
    Ctor(lua_State *l,
         const std::string &metatable_name)
         : _ctor([metatable_name, l](lua_State *state, Args... args) {
			 void *addr = lua_newuserdata(l, sizeof(ObjPtr<T>));
			 new( addr ) ObjPtr<T>( new T(args...), true );
             luaL_setmetatable(state, metatable_name.c_str());
           }) {
        lua_pushlightuserdata(l, (void *)static_cast<BaseFun *>(this));
        lua_pushcclosure(l, &detail::_lua_dispatcher, 1);
        lua_setfield(l, -2, "new");
    }

    int Apply(lua_State *l) {
        std::tuple<detail::decay_primitive<Args>...> args = detail::_get_args<detail::decay_primitive<Args>...>(l);
        auto pack = std::tuple_cat(std::make_tuple(l), args);
        detail::_lift(_ctor, pack);
        // The constructor will leave a single userdata entry on the stack
        return 1;
    }
};
}
