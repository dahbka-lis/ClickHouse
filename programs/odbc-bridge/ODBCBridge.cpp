#include "ODBCBridge.h"

#include <iostream>

int mainEntryClickHouseODBCBridge(int argc, char ** argv)
{
    DB::ODBCBridge app;
    try
    {
        return app.run(argc, argv);
    }
    catch (...)
    {
        std::cerr << DB::getCurrentExceptionMessage(true) << "\n";
        auto code = DB::getCurrentExceptionCode();
        return static_cast<UInt8>(code) ? code : 1;
    }
}

namespace DB
{

std::string ODBCBridge::bridgeName() const
{
    return "ODBCBridge";
}

ODBCBridge::HandlerFactoryPtr ODBCBridge::getHandlerFactoryPtr(ContextPtr context) const
{
    return std::make_shared<ODBCBridgeHandlerFactory>("ODBCRequestHandlerFactory-factory", context);
}

}
