<?hh // strict

class HttpApiRouter implements ApiRouter<HttpApiOp, ImmParamMap, HttpApiHandler> {

  public function __construct(
      private ImmMap<HttpApiOp, HttpApiHandler> $routingTable
  ) {}

  public function route(HttpApiOp $op, ImmParamMap $params): HttpApiHandler {
    if (!$this->routingTable->contains($op)) {
      throw HttpApiException::unregisteredOp($op);
    }

    return $this->routingTable[$op];
  }
}
