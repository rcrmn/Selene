#pragma once

#include <selene.h>

struct Barm {
	int x;
	Barm() { x = 1; }
	bool IsBarm() { return true; }
};

struct Zoom {
	int x;
	Zoom() {
		x = 2;
	}
	bool IsZoom() { return true; }
};

struct Container
{
	Barm _Barm;
	Zoom _Zoom;
	Barm* GetBarm()
	{
		return &_Barm;
	}

	Zoom* GetZoom()
	{
		return &_Zoom;
	}
};

Container _container;


bool test_object_container(sel::State &state)
{
	//state( "reg = debug.getregistry ()" );

	state["Barm"].SetClass<Barm>("x", &Barm::x, "IsBarm", &Barm::IsBarm);
	//state( "print('-> Barm class registered')" );
	//state( "print('----- registry')" );
	//state( "for key,value in pairs(reg) do print(key,value) end" );
	//state( "print('----- names')" );
	//state( "for key,value in pairs(reg['selene_metatable_names']) do print(key,value) end" );
	//state( "print('----- tables')" );
	//state( "for key,value in pairs(reg['selene_metatables']) do print(key,value) end" );
	//state( "print('-----')" );

	state["Zoom"].SetClass<Zoom>("x", &Zoom::x, "IsZoom", &Zoom::IsZoom);
	//state( "print('-> Zoom class registered')" );
	//state( "print('----- registry')" );
	//state( "for key,value in pairs(reg) do print(key,value) end" );
	//state( "print('----- names')" );
	//state( "for key,value in pairs(reg['selene_metatable_names']) do print(key,value) end" );
	//state( "print('----- tables')" );
	//state( "for key,value in pairs(reg['selene_metatables']) do print(key,value) end" );
	//state( "print('-----')" );

	state["Container"].SetObj( _container, "GetBarm", &Container::GetBarm, "GetZoom", &Container::GetZoom );


	bool r;

	//state( "print('-> getting Barm instance')" );

	state( "b = Container:GetBarm();" );
	state( "r = b.IsBarm ~= nil and b:IsBarm();" );
	r = state["r"];

	//state( "print('-> Barm instance:', b)" );
	//state( "print('-> Barm instance metatable:', getmetatable(b))" );
	//state( "for key,value in pairs(getmetatable(b)) do print(key,value) end" );

	//state( "print('-> getting Zoom instance')" );

	state( "z = Container:GetZoom();" );
	state( "r = z.IsZoom ~= nil and z:IsZoom();" );
	r = r && state["r"];

	//state( "print('-----')" );
	//state( "print('-> Barm instance:', b)" );
	//state( "print('-> Barm instance metatable:', getmetatable(b))" );
	//state( "for key,value in pairs(getmetatable(b)) do print(key,value) end" );

	//state( "print('-----')" );
	//state( "print('-> Zoom instance:', z)" );
	//state( "print('-> Zoom instance metatable:', getmetatable(z))" );
	//state( "for key,value in pairs(getmetatable(z)) do print(key,value) end" );

	//state( "print('----- registry')" );
	//state( "for key,value in pairs(reg) do print(key,value) end" );
	//state( "print('----- names')" );
	//state( "for key,value in pairs(reg['selene_metatable_names']) do print(key,value) end" );
	//state( "print('----- tables')" );
	//state( "for key,value in pairs(reg['selene_metatables']) do print(key,value) end" );
	//state( "print('-----')" );


	state( "r = b.IsBarm ~= nil and b:IsBarm();" );
	r = r && state["r"];

	return r;
}
