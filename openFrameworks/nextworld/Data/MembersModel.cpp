//
//  MembersModel.cpp
//  NextWorld
//
//  Created by SakuragiYoshimasa on 2016/02/23.
//
//

#include "MembersModel.hpp"

void MembersModel::load_data(){
    members = CSVLoadHandler::loadMembersDataFromCSV("03_20-3_24keio.csv");
}