#include "lua_api.h"
#include "model_select.h"

// Lua-Funktion, die `selectModel()` aufruft
static int lua_selectModel(lua_State *L)
{
    int modelIndex = luaL_checkinteger(L, 1); // Lua-Parameter holen
    if (modelIndex >= 0 && modelIndex < MAX_MODELS) { // Gültige Modelle prüfen
        selectModel((uint8_t) modelIndex); // Modellwechsel ausführen
    }
    return 0;
}

// Lua-Funktionsliste definieren
static const luaL_Reg modelLib[] = {
    { "selectModel", lua_selectModel },
    { NULL, NULL }
};

// Funktion zum Registrieren der Lua-Funktion
extern "C" int luaopen_model(lua_State *L)
{
    luaL_newlib(L, modelLib);
    return 1;
}
