//
//  AssignmentActionFactory.cpp
//  assignment-client/src/
//
//  Created by Seth Alves on 2015-6-19
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "AssignmentActionFactory.h"


EntityActionPointer assignmentActionFactory(EntityActionType type, QUuid id, EntityItemPointer ownerEntity) {
    return (EntityActionPointer) new AssignmentAction(type, id, ownerEntity);
}


EntityActionPointer AssignmentActionFactory::factory(EntitySimulation* simulation,
                                                     EntityActionType type,
                                                     QUuid id,
                                                     EntityItemPointer ownerEntity,
                                                     QVariantMap arguments) {
    EntityActionPointer action = assignmentActionFactory(type, id, ownerEntity);
    if (action) {
        bool ok = action->updateArguments(arguments);
        if (ok) {
            ownerEntity->addAction(simulation, action);
            return action;
        }
    }
    return action;
}


EntityActionPointer AssignmentActionFactory::factoryBA(EntitySimulation* simulation,
                                                       EntityItemPointer ownerEntity,
                                                       QByteArray data) {
    QDataStream serializedActionDataStream(data);
    EntityActionType type;
    QUuid id;

    serializedActionDataStream >> type;
    serializedActionDataStream >> id;

    EntityActionPointer action = assignmentActionFactory(type, id, ownerEntity);

    action->deserialize(data);
    ownerEntity->addAction(simulation, action);
    return action;
}
