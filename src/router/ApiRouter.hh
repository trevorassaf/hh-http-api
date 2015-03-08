<?hh // strict

/**
 * Used to select the handler to process a particular operation.
 */
interface ApiRouter<TOp, TParams, THandler> {
  
  public function route(TOp $op_type, TParams $params): THandler;
}
