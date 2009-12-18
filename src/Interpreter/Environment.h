#pragma once

#include <iostream>
#include <vector>

#include "Macros.h"
#include "Object.h"
#include "Ref.h"
#include "Scope.h"

namespace Finch
{
    using std::vector;
    
    class BlockObject;
    class Expr;
    
    //### bob: this should be a DynamicObject.
    // Represents the global runtime environment. Code is executed withing the
    // context of this object. It provides access to global variables as well
    // as tracking the current local scope and other contextual information.
    class Environment
    {
    public:
        Environment();
        
        Ref<Scope>  Globals()       const { return mGlobals; }
        Ref<Scope>  CurrentScope()  const { return mCurrentScope; }

        Ref<Object> Self()          const { return mSelf; }

        Ref<Object> Nil()           const { return mNil; }
        Ref<Object> Block()         const { return mBlock; }
        Ref<Object> Number()        const { return mNumber; }
        Ref<Object> String()        const { return mString; }
        Ref<Object> True()          const { return mTrue; }
        Ref<Object> False()         const { return mFalse; }
        
        Ref<Object> EvaluateBlock(const BlockObject * block,
                                  const vector<Ref<Object> > & args);
        Ref<Object> EvaluateMethod(Ref<Object> self,
                                   const BlockObject * block,
                                   const vector<Ref<Object> > & args);
        
    private:
        Ref<Scope> mGlobals;
        Ref<Scope> mCurrentScope;
        Ref<Object> mSelf;
        Ref<Object> mNil;
        Ref<Object> mBlock;
        Ref<Object> mNumber;
        Ref<Object> mString;
        Ref<Object> mTrue;
        Ref<Object> mFalse;
    };
}