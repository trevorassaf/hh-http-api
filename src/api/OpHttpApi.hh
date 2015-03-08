<?hh // strict

/**
 * Map of http api operation => handler class name.
 */
newtype HttpApiRoutingTable = ImmMap<HttpApiOp, HttpApiHandler>;

class OpHttpApi implements HttpApi {

  const PAYLOAD_KEY = 'payload';

  public function __construct(
    private HttpApiRoutingTable $router
  ) {}

  final public function process(HttpParams $params): string {
    // Process provided http params
    $post_output = $this->processPostParams($params->getPostParams()); 
    $get_output = $this->processGetParams($params->getGetParams());

    // We shouldn't receive output from both the post 
    // handler and the get handler
    if ($post_output != '' && $get_output != '') {
      throw HttpApiException::dualOutput();
    }

    return $post_output != '' ? $get_output : $post_output;
  }
  
  protected function processPostParams(ImmParamMap $post_map): string {
    // POST payloads should contain single key
    if ($post_map->count() != 1) {
      throw HttpApiException::badPostParamCount();
    }

    // All POST payloads should contain a top-level payload key
    if (!$post_map->contains(self::PAYLOAD_KEY)) {
      throw HttpApiException::missingPayloadKey();
    }

    $serialized_payload = (string)$post_map[self::PAYLOAD_KEY];
    $deserialized_payload = json_decode($serialized_payload);

    // The payload must contain valid json
    if (!$deserialized_payload) {
      throw HttpApiException::invalidJson($serialized_payload);   
    }


    
    return '';
  }

  protected function processGetParams(ImmParamMap $get_map): string {
    return '';
  }
}
