# example.thrift
namespace cpp tamvm

service ExampleService {
  i64 get_number(1:i32 number);  
}


struct EchoRequest {
    1: string message,
    // 255: optional base.Base Base,
}

struct EchoResponse {
    1: string message,
    // 255: optional base.BaseResp BaseResp,
}

service EchoService {
    EchoResponse echo(1:EchoRequest request),
    oneway void oneway_echo(1:EchoRequest request),
}
