<?hh // strict

newtype RoutingTable = ImmMap<HttpApiOp, HttpApiHandler>;

