//
//  FacadePattern.cpp
//  CppDpLearning
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//  Copyright © 2016年 SakuragiYoshimasa. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*
 Decorator ; インターフェイスを変更せずに責務を追加する。
 Adaptor   : あるインターフェイスを別のインターフェイスに変換する。
 Facade    : インターフェイスをより簡潔にする。
 */

//サブシステムをカプセル化するわけではなくサブシステムの機能に対する
//簡素なインターフェイスを提供する

/*
 サブシステムの一連のインターフェイスに対する
 統合されたインターフェイスを提供する。
 サブシステムをより使いやすくする高水準のインターフェイスを定義する。
 */