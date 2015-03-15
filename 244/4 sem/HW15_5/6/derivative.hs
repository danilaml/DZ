import Test.QuickCheck

data Expression = Var
                | Const Int
                | Expression :+: Expression
                | Expression :-: Expression
                | Expression :*: Expression
                | Expression :^: Int
                deriving (Eq, Show)

simplify1 :: Expression -> Expression
simplify1 x = case x of
    (Const n1 :+: Const n2) -> Const (n1 + n2)
    (Const n1 :-: Const n2) -> Const (n1 - n2)
    (Const 1 :*: rest)      -> simplify rest
    (rest :*: Const 1)      -> simplify rest
    (Const n1 :*: Const n2) -> Const (n1 * n2)
    (Const n1 :^: n2)       -> Const (n1 ^ n2)
    (_ :^: 0)               -> Const 1
    (e :^: 1)               -> e
    (e :+: Const 0)         -> e
    (e :-: Const 0)         -> e
    (e :*: Const 0)         -> Const 0
    (Const 0 :+: e)         -> e
    (Const 0 :-: e)         -> e
    (Const 0 :*: e)         -> Const 0
    ((e1 :+: e2) :*: e)     -> simplify ((e1 :*: e) :+: (e2 :*: e))
    (e :*: (e1 :+: e2))     -> simplify ((e :*: e1) :+: (e :*: e2))
    ((e1 :-: e2) :*: e)     -> simplify ((e1 :*: e) :-: (e2 :*: e))
    (e :*: (e1 :-: e2))     -> simplify ((e :*: e1) :-: (e :*: e2))
    ((Const n1 :*: e1) :*: 
     (Const n2 :*: e2))     -> Const (n1 * n2) :*: (e1 :*: e2)
    ((Const n1 :*: e1) :*: 
     (e2 :*: Const n2))     -> Const (n1 * n2) :*: (e1 :*: e2)
    ((e1 :*: Const n1) :*: 
     (e2 :*: Const n2))     -> Const (n1 * n2) :*: (e1 :*: e2)
    ((e1 :*: Const n1) :*: 
     (Const n2 :*: e2))     -> Const (n1 * n2) :*: (e1 :*: e2)
    ((e1 :*: Const n1) :*:
     Const n2)              -> e1 :*: Const (n1 * n2)
    ((Const n1 :*: e1) :*:
     Const n2)              -> e1 :*: Const (n1 * n2)
    (Const n1 :*:
     (e1 :*: Const n2))     -> e1 :*: Const (n1 * n2)
    (Const n1 :*:
     (Const n2 :*: e1))     -> e1 :*: Const (n1 * n2)
    _                       -> x

simplify :: Expression -> Expression
simplify (e1 :+: e2)    = simplify1 $ (simplify e1) :+: (simplify e2)
simplify (e1 :-: e2)    = simplify1 $ (simplify e1) :-: (simplify e2)
simplify (e1 :*: e2)    = simplify1 $ (simplify e1) :*: (simplify e2)
simplify (e :^: n)      = simplify1 $ (simplify e) :^: n
simplify x              = x
                
derivative' :: Expression -> Expression
derivative' (Const _)   = Const 0
derivative' (e1 :+: e2) = (derivative' e1) :+: (derivative' e2)
derivative' (e1 :-: e2) = (derivative' e1) :-: (derivative' e2)
derivative' (e1 :*: e2) = ((derivative' e1) :*: e2) :+: (e1 :*: (derivative' e2))
derivative' (e :^: n)   = ((Const n) :*: (e :^: (n - 1))) :*: (derivative' e)
derivative' (Var)       = Const 1

derivative :: Expression -> Expression
derivative x = simplify $ derivative' $ simplify x

calculate :: Expression -> Int -> Int
calculate e v = case e of
    (e1 :+: e2) -> (calculate e1 v) + (calculate e2 v)
    (e1 :-: e2) -> (calculate e1 v) - (calculate e2 v)
    (e1 :*: e2) -> (calculate e1 v) * (calculate e2 v)
    (e :^: n)   -> (calculate e v) ^ n
    (Const n)   -> n
    (Var)       -> v

testexp1  = ((Const 1 :+: Var) :^: 3) :*: ((Var :^: 2) :*: Const 3) -- (1+x)^3 * 3x^2
testexp1d = ((Const 9 :*: ((Const 1 :+: Var) :^: 2)) :*: (Var :^: 2)) :+:
                ((Const 6 :*: ((Const 1 :+: Var) :^: 3)) :*: Var)   -- 9(1+x)^2*x^2 + 6(1+x)^3*x
testexp2  = (Var :^: 2) :+: (Var :^: 3) :+: Const 1                 -- x^2 + x^3 + 1
testexp2d = (Const 2 :*: Var) :+: (Const 3 :*: (Var :^: 2))         -- 2x + 3x^2

main = do
    quickCheck (\s -> calculate (derivative testexp1) s == calculate testexp1d s)
    quickCheck (\s -> calculate (derivative testexp2) s == calculate testexp2d s)