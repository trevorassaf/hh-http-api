<?hh // strict

interface HttpApiHandler implements ApiHandler<ImmParamMap, string> {
  public function handle(ImmParamMap $params): string;
}
