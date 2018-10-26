//
//  AdditionScriptingInterface.h
//  hifi
//
//  Created by Raveena Jain on 10/25/18.
//

#ifndef AdditionScriptingInterface_h
#define AdditionScriptingInterface_h

#include <QObject>

class AdditionScriptingInterface : public QObject {
    Q_OBJECT
public:
    template <class T>
    T addTwo(T x, T y);
};

#endif /* AdditionScriptingInterface_h */
