/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <json.hpp>

#include <fstream>
#include <infra/config/iroha_config_with_json.hpp>
#include <consensus/connection/connection.hpp>
#include <thread>

using Api::DiscoverRequest;
using Api::Peer;

int main(int argc, char* argv[]) {
    std::vector<std::string> defaultHosts {};
    auto trustedHosts = config::IrohaConfigManager::getInstance().getTrustedHosts(defaultHosts);
    if (trustedHosts.empty()) {
        std::cout << "Config section for trusted hosts was not found or it is empty." << std::endl;
        return 1;
    }

    DiscoverRequest request;
    request.set_message("discovery");
    for (auto host: trustedHosts) {
        Peer peer = connection::iroha::HostDiscovery::getHostInfo::send(host, request);
        if (peer.publickey() != "") {
            std::cout << peer.address() << " " << peer.publickey() << std::endl;
        }
    }

    return 0;
}