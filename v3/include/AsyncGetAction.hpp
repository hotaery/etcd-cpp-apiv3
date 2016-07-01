#ifndef __ASYNC_GET_HPP__
#define __ASYNC_GET_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncRangeResponse.hpp"


using grpc::ClientAsyncResponseReader;
using etcdserverpb::RangeResponse;
using etcdserverpb::KV;

namespace etcdv3
{
  class AsyncGetAction : public etcdv3::Action
  {
    public:
      AsyncGetAction(std::string const & key, KV::Stub* stub_, bool withPrefix=false);
      AsyncRangeResponse ParseResponse();
      RangeResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<RangeResponse>> response_reader;
      bool prefix;
  };
}

#endif