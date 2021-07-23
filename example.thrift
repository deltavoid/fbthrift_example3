# example.thrift
namespace cpp tamvm


struct EchoRequest {
    1: i32 id,
    2: string message,
}

struct EchoResponse {
    1: i32 id,
    2: string message,
}

service EchoService {
    EchoResponse echo(1:EchoRequest request),
    // oneway void oneway_echo(1:EchoRequest request),
}
