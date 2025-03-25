#include "sdcard_common.h"  // Die Datei, die `selectModel` enthält
#include "lua_api.h"

// Lua-Wrapper für `selectModel` erstellen
static int lua_selectModel(lua_State *L)
{
    // Holen des Modellindex aus Lua
    int modelIndex = luaL_checkinteger(L, 1);
    
    // Sicherstellen, dass der Index gültig ist
    if (modelIndex >= 0 && modelIndex < MAX_MODELS) {
        selectModel((uint8_t)modelIndex);  // Modell wechseln
    }
    
    return 0;  // Keine Rückgabewerte
}

// Registrieren der Lua-Funktion
static const luaL_Reg modelLib[] = {
    { "selectModel", lua_selectModel },
    { NULL, NULL }
};

// Lua-Bibliothek für `selectModel` registrieren
extern "C" int luaopen_model(lua_State *L)
{
    luaL_newlib(L, modelLib);  // Die Bibliothek laden
    return 1;
}
