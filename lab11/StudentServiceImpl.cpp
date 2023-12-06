//
// Created by Toni on 2023. 12. 06..
//

#include "StudentServiceImpl.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    return this->dao->students.find(id) == this->dao->students.end();
}
