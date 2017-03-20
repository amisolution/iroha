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

package instances.sample;

import api.*;
//import transaction;
import java.util.HashMap;

import static repository.KeyConstants.*;

public class SpecialTransfer {
  Transaction invoke(Transaction tx) {
    Transaction outputTx = new Transaction();

    outputTx.sender = tx.sender;
    outputTx.receiver = tx.receiver;

    Date d = new Date();
    if (d.day == "Thursday") {
        outputTx.value = tx.asset.value + tx.asset.value * 0.1;
    }

    return outputTx;
  }
}