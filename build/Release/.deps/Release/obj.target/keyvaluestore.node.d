cmd_Release/obj.target/keyvaluestore.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=keyvaluestore.node -o Release/obj.target/keyvaluestore.node -Wl,--start-group Release/obj.target/keyvaluestore/KeyValueStoreImpl.o Release/obj.target/keyvaluestore/Binding.o -Wl,--end-group 
