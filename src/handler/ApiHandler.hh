<?hh // strict

interface ApiHandler<TParams, TOutput> {
  
  public function handle(TParams $params): TOutput;
}
