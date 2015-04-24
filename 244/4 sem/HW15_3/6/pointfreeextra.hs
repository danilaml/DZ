{-
func f g l = filter f (map g l)

func f g = (filter f) . (map g)

func f = ((filter f) .) . (map) == (.) ((.) (filter f)) (map)
 == (flip (.)) (map) ((.) (filter f))

func = (.) ((flip (.)) (map)) ((.) . filter) == (.) (. map) ((.) . filter)
 == (. map) . (.) . filter
-}

func = (. map) . (.) . filter